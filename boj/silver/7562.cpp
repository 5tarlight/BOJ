#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    int dx[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    int dy[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    while (t--) {
        int n;
        cin >> n;
        int x0, y0;
        cin >> x0 >> y0;
        int xt, yt;
        cin >> xt >> yt;

        bool visited[n][n];
        memset(visited, false, sizeof(visited));
        int dist[n][n];
        memset(dist, 0x3f, sizeof(dist));
        dist[x0][y0] = 0;
        visited[x0][y0] = true;

        queue<pair<int, int>> q;
        q.push({ x0, y0 });
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x == xt && y == yt) {
                cout << dist[x][y] << '\n';
                break;
            }

            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny])
                    continue;

                visited[nx][ny] = true;
                dist[nx][ny] = dist[x][y] + 1;
                q.push({ nx, ny });
            }
        }
    }
}
