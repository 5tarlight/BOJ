#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, int>> adj[n + 1]; // { cost, nxt }
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ w, v });
    }

    int d[n + 1];
    fill(d, d + n + 1, 1e9);
    d[k] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({ d[k], k });

    while (!pq.empty()) {
        auto [cost, cur] = pq.top();
        pq.pop();

        if (cost > d[cur]) continue;

        for (auto &[nxtCost, nxt]: adj[cur]) {
            if (cost + nxtCost < d[nxt]) {
                d[nxt] = cost + nxtCost;
                pq.push({ d[nxt], nxt });
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (d[i] == 1e9)
            cout << "INF\n";
        else
            cout << d[i] << '\n';
    }
}
