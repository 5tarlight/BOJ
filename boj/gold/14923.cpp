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
    int hx, hy;
    cin >> hx >> hy;
    int ex, ey;
    cin >> ex >> ey;
    int graph[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> graph[i][j];
    bool visited[n][m][2];
    int dist[n][m][2];
    memset(visited, false, sizeof(visited));
    int dx[] = { -1, 1, 0, 0 };
    int dy[] = { 0, 0, -1, 1 };

    hx--; hy--; ex--; ey--;

    queue<pair<pair<int, int>, bool>> q;
    q.push({{ hx, hy }, false });
    visited[hx][hy][0] = true;
    dist[hx][hy][0] = 0;
    while (!q.empty()) {
        auto [pos, broke] = q.front();
        auto [x, y] = pos;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny][broke])
                continue;

            if (graph[nx][ny] == 0) {
                visited[nx][ny][broke] = true;
                dist[nx][ny][broke] = dist[x][y][broke] + 1;
                q.push({{ nx, ny }, broke });
            } else {
                if (!broke) {
                    visited[nx][ny][1] = true;
                    dist[nx][ny][1] = dist[x][y][0] + 1;
                    q.push({{ nx, ny }, 1 });
                }
            }
        }
    }

    if (visited[ex][ey][0] && visited[ex][ey][1])
        cout << min(dist[ex][ey][0], dist[ex][ey][1]);
    else if (visited[ex][ey][0])
        cout << dist[ex][ey][0];
    else if (visited[ex][ey][1])
        cout << dist[ex][ey][1];
    else
        cout << -1;
}
