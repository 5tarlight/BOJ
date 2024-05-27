#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n, d, c;
        cin >> n >> d >> c;

        vector<vector<pair<int, int>>> graph(n);

        while (d--) {
            int a, b, s;
            cin >> a >> b >> s;
            graph[b - 1].emplace_back(a - 1, s);
        }

        vector<int> dist(n, 1e9);
        dist[c - 1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, c - 1});

        while (!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();

            if (cost > dist[u])
                continue;

            for (const auto& [v, weight] : graph[u]) {
                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        int cnt = 0, max_dist = 0;
        for (int i = 0; i < n; i++) {
            if (dist[i] != 1e9) {
                cnt++;
                if (dist[i] > max_dist)
                    max_dist = dist[i];
            }
        }

        cout << cnt << ' ' << max_dist << '\n';
    }
}
