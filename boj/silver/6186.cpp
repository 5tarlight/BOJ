#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int r, c;
    cin >> r >> c;
    char graph[r][c + 1];
    for (int i = 0; i < r; i++) {
        cin >> graph[i];
    }
    bool visited[r][c];
    memset(visited, false, sizeof(visited));

    int ans = 0;
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (visited[i][j] || graph[i][j] == '.')
                continue;

            queue<pair<int, int>> q;
            q.push({i, j});
            visited[i][j] = true;
            ans++;

            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (nx < 0 || nx >= r || ny < 0 || ny >= c)
                        continue;

                    if (visited[nx][ny] || graph[nx][ny] == '.')
                        continue;

                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }

    cout << ans;
}
