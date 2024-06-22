#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    int graph[n][n];
    int s, x, y;
    queue<pair<int, int>> q[k + 1];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
            if (graph[i][j] != 0)
                q[graph[i][j]].push({i, j});
        }
    }
    cin >> s >> x >> y;

    int dx[] = { -1, 1, 0, 0 };
    int dy[] = { 0, 0, -1, 1 };
    while (s--) {
        for (int i = 1; i <= k; i++) {
            if (q[i].empty())
                continue;
            int size = q[i].size();

            while (size--) {
                auto [x, y] = q[i].front();
                q[i].pop();

                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n || graph[nx][ny] != 0)
                        continue;

                    graph[nx][ny] = i;
                    q[i].push({ nx, ny });
                }
            }
        }
    }

    cout << graph[x - 1][y - 1];
}
