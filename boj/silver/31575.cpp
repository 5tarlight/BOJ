#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> m >> n;
    int graph[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> graph[i][j];
    bool visited[n][m];
    memset(visited, false, sizeof(visited));

    visited[0][0] = true;
    queue<pair<int, int>> q;
    q.push({ 0, 0 });
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if (x == n - 1 && y == m - 1) {
            cout << "Yes";
            return 0;
        }

        for (int i = 0; i < 2; i++)  {
            int nx = x + "21"[i] - '1';
            int ny = y + "12"[i] - '1';
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || graph[nx][ny] == 0)
                continue;

            visited[nx][ny] = true;
            q.push({ nx, ny });
        }
    }

    cout << "No";
}
