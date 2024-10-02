#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    int x, y;
    cin >> n >> x >> y;
    vector<int> adj[n + 1];

    int m;
    cin >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<pair<int, int>> q;
    q.push({ x, 0 });
    bool visited[n + 1];
    fill(visited, visited + n + 1, false);

    while (!q.empty()) {
        auto [a, d] = q.front();
        q.pop();

        for (int nxt : adj[a]) {
            if (visited[nxt]) continue;

            visited[nxt] = true;
            q.push({ nxt, d + 1 });

            if (nxt == y) {
                cout << d + 1;
                return 0;
            }
        }
    }

    cout << -1;
}
