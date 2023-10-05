#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int r, c;
int graph[20][20];
bool visited[30];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int depth = -1;

void backtrack(int x, int y, int d) {
    if (d > depth)
        depth = d;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= r || ny < 0 || ny >= c)
            continue;
        if (visited[graph[nx][ny]])
            continue;

        visited[graph[nx][ny]] = true;
        backtrack(nx, ny, d + 1);
        visited[graph[nx][ny]] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < c; j++) {
            graph[i][j] = s[j] - 'A';
        }
    }

    visited[graph[0][0]] = true;
    backtrack(0, 0, 0);

    cout << depth + 1;
}
