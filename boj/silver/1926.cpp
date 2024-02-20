#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int graph[n][m];
    bool visited[n][m];
    int dx[] = { -1, 1, 0, 0 };
    int dy[] = { 0, 0, -1, 1 };
    for (int i = 0; i < n; i++) {
        fill(visited[i], visited[i] + m, false);
        for (int j = 0; j < m; j++)
            cin >> graph[i][j];
    }

    queue<pair<int, int>> q;
    int cnt = 0;
    int area = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j] || graph[i][j] == 0)
                continue;

            q.emplace(i, j);
            visited[i][j] = true;
            cnt++;
            int larea = 1;

            while (!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for (int c = 0; c < 4; c++) {
                    int nx = x + dx[c];
                    int ny = y + dy[c];

                    if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                        continue;
                    if (visited[nx][ny] || graph[nx][ny] == 0)
                        continue;

                    visited[nx][ny] = true;
                    q.emplace(nx, ny);
                    larea++;
                }
            }

            if (larea > area)
                area = larea;
        }
    }

    cout << cnt << '\n' << area;
}
