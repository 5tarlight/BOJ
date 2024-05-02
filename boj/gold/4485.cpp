#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    for (int k = 1; true; k++) {
        int n;
        cin >> n;

        if (n == 0)
            break;

        int graph[n][n];
        int dist[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cin >> graph[i][j];
            fill(dist[i], dist[i] + n, 1e9);
        }

        dist[0][0] = graph[0][0];
        priority_queue<
                pair<int, pair<int, int>>,
                vector<pair<int, pair<int, int>>>,
                greater<>
        > pq;
        pq.push({dist[0][0], {0, 0}});

        // Dijkstra
        while (!pq.empty()) {
            auto [cost, cur] = pq.top();
            pq.pop();

            for (int i = 0; i < 4; i++) {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                    continue;

                if (dist[nx][ny] > dist[cur.first][cur.second] + graph[nx][ny]) {
                    dist[nx][ny] = dist[cur.first][cur.second] + graph[nx][ny];
                    pq.push({dist[nx][ny], {nx, ny}});
                }
            }
        }

        cout << "Problem " << k << ": " << dist[n - 1][n - 1] << '\n';
    }
}
