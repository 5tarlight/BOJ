#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define INF 1'000'001

int n, e;
vector<pair<int, int>> graph[801];

vector<int> dijkstra(int start) {
    vector<int> d(n + 1, INF);
    d[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, start);

    while (!pq.empty()) {
        int c = pq.top().first;
        int i = pq.top().second;
        pq.pop();

        if (c != d[i])
            continue;

        for (auto &next : graph[i]) {
            int nc = next.first;
            int ni = next.second;

            if (d[ni] <= d[i] + nc)
                continue;

            d[ni] = d[i] + nc;
            pq.emplace(d[ni], ni);
        }
    }

    return d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> e;

    while (e--) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].emplace_back(c, b);
        graph[b].emplace_back(c, a);
    }

    int v1, v2;
    cin >> v1 >> v2;

    auto s1 = dijkstra(1);
    auto sv1 = dijkstra(v1);
    auto sv2 = dijkstra(v2);

    // 1 -> v1 -> v2 -> n
    // 1 -> v2 -> v1 -> n
    int d1 = s1[v1] + sv1[v2] + sv2[n];
    int d2 = s1[v2] + sv2[v1] + sv1[n];

    if (s1[v1] == INF ||  sv1[v2] == INF || sv2[n] == INF)
        d1 = INF;
    if (s1[v2] == INF || sv2[v1] == INF || sv1[n] == INF)
        d2 = INF;

    int ans = min(d1, d2);

    if (ans == INF)
        cout << -1;
    else
        cout << ans;
}
