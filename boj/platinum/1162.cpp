#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

typedef long long ll;

struct V {
    ll cost;
    int nxt;
    int pave;

    bool operator<(const V& v) const {
        return cost > v.cost;
    }
};

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<ll, int>> adj[n + 1]; // { cost, node }
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({ c, b });
        adj[b].push_back({ c, a });
    }

    ll dist[n + 1][k + 1];
    memset(dist, 0x3f, sizeof(dist));

    priority_queue<V> pq;
    pq.push({ 0, 1, 0 });
    dist[1][0] = 0;

    while (!pq.empty()) {
        int cur = pq.top().nxt;
        ll cost = pq.top().cost;
        int p = pq.top().pave;
        pq.pop();

        if (dist[cur][p] < cost) continue;

        for (auto& [ncost, nnode] : adj[cur]) {
            ll new_cost = cost + ncost;

            if (new_cost < dist[nnode][p]) {
                dist[nnode][p] = new_cost;
                pq.push({ new_cost, nnode, p });
            }

            if (p < k && cost < dist[nnode][p + 1]) {
                dist[nnode][p + 1] = cost;
                pq.push({ cost, nnode, p + 1 });
            }
        }
    }

    ll ans = 1e18;
    for (int i = 0; i <= k; i++)
        ans = min(ans, dist[n][i]);

    cout << ans;
}
