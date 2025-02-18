#include "bits/stdc++.h"

using namespace std;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int getDir(int cur, char dir) {
    if (dir == 'L') return (cur + 3) % 4;
    else return (cur + 1) % 4;
}

int n, k;
int board[101][101];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    while (k--) {
        int a, b;
        cin >> a >> b;
        board[a][b] = -1;
    }

    int l;
    cin >> l;
    pair<int, char> d[l];
    for (int i = 0; i < l; i++)
        cin >> d[i].first >> d[i].second;

    deque<pair<int, int>> snake;
    snake.push_back({ 1, 1 });
    int dir = 1;
    int dirIdx = 0;
    int time = 0;
    board[1][1] = 1;

    while (true) {
        int nx = snake.front().first + dx[dir];
        int ny = snake.front().second + dy[dir];
        time++;

        if (nx <= 0 || ny <= 0 || nx > n || ny > n) {
            cout << time;
            return 0;
        }

        if (board[nx][ny] == 1) {
            cout << time;
            return 0;
        } else if (board[nx][ny] == 0) {
            auto [px, py] = snake.back();
            board[px][py] = 0;
            snake.pop_back();
        }

        board[nx][ny] = 1;
        snake.push_front({ nx, ny });

        if (dirIdx < l && d[dirIdx].first == time) {
            dir = getDir(dir, d[dirIdx].second);
            dirIdx++;
        }
    }
}
