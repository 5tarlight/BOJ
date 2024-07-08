#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> graph[n + 1]; // { cost, destination }
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ c, b });
        graph[b].push_back({ c, a });
    }

    int dist[n + 1];
    fill(dist, dist + n + 1, 1e9);
    dist[1] = 0;

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<>
    > pq;
    pq.push({ dist[1], 1 });

    while (!pq.empty()) {
        auto [cost, x] = pq.top();
        pq.pop();

        if (cost != dist[x])
            continue;

        for (auto &[nxtCost, nxt] : graph[x]) {
            if (dist[nxt] > dist[x] + nxtCost) {
                dist[nxt] = dist[x] + nxtCost;
                pq.push({ dist[nxt], nxt });
            }
        }
    }

    cout << dist[n];
}
