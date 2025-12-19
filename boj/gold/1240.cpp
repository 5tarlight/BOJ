#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    int n, m; cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({ b, c });
        adj[b].push_back({ a, c });
    }

    while (m--) {
        int a, b; cin >> a >> b;
        bool visited[n + 1];
        memset(visited, false, sizeof(visited));
        queue<pair<int, int>> q;
        q.push({ a, 0 });
        visited[a] = true;
        int ans = -1;

        while (!q.empty()) {
            auto [cur, dist] = q.front(); q.pop();
            if (cur == b) {
                ans = dist;
                break;
            }

            for (auto [nxt, w] : adj[cur]) {
                if (!visited[nxt]) {
                    visited[nxt] = true;
                    q.push({ nxt, dist + w });
                }
            }
        }

        cout << ans << '\n';
    }
}
