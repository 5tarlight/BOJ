#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    int n, m; cin >> n >> m;
    int deg[n + 1];
    vector<int> adj[n + 1];
    memset(deg, 0, sizeof(deg));

    while (m--) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        deg[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (deg[i] == 0) q.push(i);

    vector<int> ans;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        ans.push_back(u);
        for (int v : adj[u]) {
            deg[v]--;
            if (deg[v] == 0) q.push(v);
        }
    }

    for (int x : ans) cout << x << ' ';
}
