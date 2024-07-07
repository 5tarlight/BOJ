#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int graph[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    queue<pair<int, int>> q;
    bool visited[n][n];
    memset(visited, false, sizeof(visited));
    q.push({ 0, 0 });
    visited[0][0] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        int d = graph[x][y];

        int nx = x + d;
        int ny = y;
        if (!(nx >= n || ny >= n)) {
            if (nx == n - 1 && ny == n - 1) {
                cout << "HaruHaru";
                return 0;
            }

            if (!visited[nx][ny]) {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }

        }

        nx = x;
        ny = y + d;
        if (!(nx >= n || ny >= n)) {
            if (nx == n - 1 && ny == n - 1) {
                cout << "HaruHaru";
                return 0;
            }

            if (!visited[nx][ny]) {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }

    cout << "Hing";
}
