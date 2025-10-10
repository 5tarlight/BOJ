#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int v, e, p;
vector<vector<pair<int, int>>> adj; // { to, weight }

int getDist(int from, int to) {
    vector<int> dist(v + 1, 1e9);
    dist[from] = 0;

    priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<>
    > pq; // { dist, nxt }
    pq.push({0, from});

    while (!pq.empty()) {
        auto [curDist, cur] = pq.top();
        pq.pop();

        if (dist[cur] < curDist) continue;
        if (cur == to) return curDist;

        for (auto [nxt, weight] : adj[cur]) {
            int nxtDist = curDist + weight;
            if (dist[nxt] > nxtDist) {
                dist[nxt] = nxtDist;
                pq.push({nxtDist, nxt});
            }
        }
    }

    return -1;
}

int main() {
    fio();

    cin >> v >> e >> p;
    adj.resize(v + 1);
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }

    int direct = getDist(1, v);
    int viaP = getDist(1, p) + getDist(p, v);

    if (direct >= viaP) cout << "SAVE HIM" << '\n';
    else cout << "GOOD BYE" << '\n';
}
