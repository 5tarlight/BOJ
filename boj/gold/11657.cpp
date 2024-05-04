#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> graph[n + 1]; // {vertex, weight}
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
    }

    long long dist[n + 1];
    fill(dist, dist + n + 1, 1e9);
    dist[1] = 0;

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (auto &p : graph[i]) {
                int next = p.first;
                int cost = p.second;

                if (dist[i] != 1e9 && dist[next] > dist[i] + cost) {
                    dist[next] = dist[i] + cost;
                    if (k == n) {
                        cout << -1;
                        return 0;
                    }
                }
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (dist[i] == 1e9) cout << -1 << '\n';
        else cout << dist[i] << '\n';
    }
}
