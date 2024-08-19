#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m, k, x;
    cin >> n >> m >> k >> x;
    vector<int> adj[n + 1];

    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    int dist[n + 1];
    fill(dist, dist + n + 1, 1e9);
    dist[x] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({ 0, x });

    while (!pq.empty()) {
        auto [cost, cur] = pq.top();
        pq.pop();

        if (cost > dist[cur]) continue;

        for (int nxt : adj[cur]) {
            if (dist[nxt] > cost + 1) {
                dist[nxt] = cost + 1;
                pq.push({ cost + 1, nxt });
            }
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == k) {
            cout << i << '\n';
            cnt++;
        }
    }

    if (cnt == 0)
        cout << -1;
}
