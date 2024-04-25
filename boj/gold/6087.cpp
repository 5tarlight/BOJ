#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

char graph[100][101];
int dist[100][100][4];
int n, m;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
int a, b;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> m >> n;
    queue<pair<pair<int, int>, pair<int, int>>> q; // x, y, direction, dist
    for (int i = 0; i < n; i++) {
        cin >> graph[i];
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 4; k++) {
                dist[i][j][k] = -1;
            }
        }

        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 'C') {
                if (q.empty()) {
                    for (int k = 0; k < 4; k++) {
                        dist[i][j][k] = 0;
                        q.push({ {i, j}, {k, 0} });
                    }
                } else {
                    a = i;
                    b = j;
                }
            }
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front().first;
        auto [dir, d] = q.front().second;
        q.pop();

        if (x == a && y == b)
            continue;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nd;
            if (dir == i)
                nd = d;
            else
                nd = d + 1;

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || graph[nx][ny] == '*')
                continue;
            if (dist[nx][ny][i] != -1 && dist[nx][ny][i] <= nd)
                continue;

            dist[nx][ny][i] = nd;
            q.push({ {nx, ny}, {i, nd} });
        }
    }

    int ans = 1e9;
    for (int i = 0; i < 4; i++) {
        if (dist[a][b][i] != -1)
            ans = min(ans, dist[a][b][i]);
    }

    cout << ans;
}
