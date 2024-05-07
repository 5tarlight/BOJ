#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int dx[] = { -1, 1, 1, -1, 1, -1, 0 };
int dy[] = { 1, 1, 0, 0, -1, -1, -1 };

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int sx, sy;
    char graph[n][n + 1];
    for (int i = 0; i < n; i++) {
        cin >> graph[i];

        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 'F') {
                sx = i;
                sy = j;
            }
        }
    }

    bool visited[n][n];
    memset(visited, false, sizeof(visited));

    int ans = 0;
    queue<pair<int, int>> q;
    q.push({ sx, sy });
    visited[sx][sy] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 7; i++) {
            int nx = x + dy[i];
            int ny = y + dx[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny] || graph[nx][ny] == '#')
                continue;

            ans++;
            visited[nx][ny] = true;
            q.push({ nx, ny });
        }
    }

    cout << ans;
}
