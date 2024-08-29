#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1][2];

    while (m--) {
        int s, e, t;
        cin >> s >> e >> t;
        adj[s][t].push_back(e);
        adj[e][t].push_back(s); // 양방향
    }

    int a, b;
    cin >> a >> b;

    vector<vector<int>> dist(n + 1, vector<int>(2, 1e9));
    deque<pair<int, int>> q;

    q.push_front({a, 0});
    q.push_front({a, 1});
    dist[a][0] = dist[a][1] = 0;

    while (!q.empty()) {
        auto [cur, type] = q.front();
        q.pop_front();

        for (int nxt : adj[cur][type]) {
            if (dist[nxt][type] == -1 || dist[nxt][type] > dist[cur][type]) {
                dist[nxt][type] = dist[cur][type];
                q.push_front({nxt, type});
            }
        }

        for (int nxt : adj[cur][1 - type]) {
            if (dist[nxt][1 - type] == -1 || dist[nxt][1 - type] > dist[cur][type] + 1) {
                dist[nxt][1 - type] = dist[cur][type] + 1;
                q.push_back({nxt, 1 - type});
            }
        }
    }

    int answer = min(dist[b][0], dist[b][1]);
    cout << answer << '\n';

    return 0;
}
