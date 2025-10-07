#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    int n, x1, x2;
    cin >> n >> x1 >> x2;
    x1--; x2--;

    vector<pair<int, int>> adj[n];

    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    vector<int> p(n, -1);
    vector<int> w(n, 0);
    queue<int> q;
    q.push(x1);
    p[x1] = x1;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto [v, weight] : adj[u]) {
            if (p[v] == -1) {
                p[v] = u;
                w[v] = weight;
                q.push(v);
            }
        }
    }

    vector<int> path;
    int cur = x2;
    int sum = 0, mx = 0;
    while (cur != x1) {
        path.push_back(w[cur]);
        sum += w[cur];
        mx = max(mx, w[cur]);
        cur = p[cur];
    }

    cout << sum - mx;
}
