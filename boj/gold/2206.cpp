#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

int n, m;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
string map[1000];
int visited[2][1000][1000];

void bfs() {
    queue<tuple<int, int, int>> q;
    q.emplace(0, 0, 0);

    int x, y, destroy;
    int nx, ny;
    int d;

    while (!q.empty()) {
        tie(x, y, destroy) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];
            d = visited[destroy][x][y] + 1;

            if (nx == n - 1 && ny == m - 1) {
                cout << d + 1;
                return;
            }

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (map[nx][ny] == '1' && destroy == 0 && visited[1][nx][ny] == -1) {
                q.emplace(nx, ny, 1);
                visited[1][nx][ny] = d;
            } else if (map[nx][ny] == '0' && visited[destroy][nx][ny] == -1) {
                q.emplace(nx, ny, destroy);
                visited[destroy][nx][ny] = d;
            }
        }
    }

    cout << -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> map[i];
    }

    for (auto & i : visited)
        for (int j = 0; j < n; j++)
            fill(i[j], i[j] + m, -1);
    visited[0][0][0] = 0;

    if (n == 1 && m == 1)
        cout << 1;
    else
        bfs();
}
