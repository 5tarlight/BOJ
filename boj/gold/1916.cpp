#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 1e9

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int graph[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
        fill(graph[i], graph[i] + n + 1, INF);

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (graph[a][b] > c)
            graph[a][b] = c;
    }

    int s, e;
    cin >> s >> e;
    int dist[n + 1];
    fill(dist, dist + n + 1, INF);
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [cost, node] = pq.top();
        pq.pop();

        for (int i = 1; i <= n; i++) {
            if (dist[i] > dist[node] + graph[node][i]) {
                dist[i] = dist[node] + graph[node][i];
                pq.push({dist[i], i});
            }
        }
    }

    cout << dist[e];
}
