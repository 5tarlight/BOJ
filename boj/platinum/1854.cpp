#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> adj[n + 1]; // { cost, dest }
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({ c, b });
    }

    using ll = long long;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    priority_queue<ll> dist[n + 1];
    dist[1].push(0);
    pq.push({ 0, 1 });

    while (!pq.empty()) {
        auto [cost, cur] = pq.top();
        pq.pop();

        for (auto [nxtCost, nxt] : adj[cur]) {
            if (dist[nxt].size() == k) {
                if (dist[nxt].top() > cost + nxtCost) {
                    dist[nxt].pop();
                    dist[nxt].push(cost + nxtCost);
                    pq.push({ cost + nxtCost, nxt });
                }
            } else {
                dist[nxt].push(cost + nxtCost);
                pq.push({ cost + nxtCost, nxt });
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i].size() < k)
            cout << "-1\n";
        else
            cout << dist[i].top() << '\n';
    }
}
