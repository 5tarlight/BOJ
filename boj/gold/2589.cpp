#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    char graph[n][m + 1];
    for (int i = 0; i < n; i++)
        cin >> graph[i];

    int ans = 0;

    int dx[] = { -1, 1, 0, 0 };
    int dy[] = { 0, 0, -1, 1 };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 'W')
                continue;
            bool visited[n][m];
            int dist[n][m];
            memset(visited, false, sizeof(visited));
            memset(dist, 0x3f, sizeof(dist));
            queue<pair<int, int>> q;
            dist[i][j] = 0;
            visited[i][j] = true;
            q.push({ i, j });

            int loc = 0;
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || graph[nx][ny] == 'W')
                        continue;

                    dist[nx][ny] = dist[x][y] + 1;
                    loc = max(loc, dist[nx][ny]);
                    visited[nx][ny] = true;
                    q.push({ nx, ny });
                }
            }

            ans = max(loc, ans);
        }
    }

    cout << ans;
}
