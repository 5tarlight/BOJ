#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define X first
#define Y second
#define INF 1'000'000'010

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int v, e;
    cin >> v >> e;

    vector<pair<int, int>> cost[v + 1]; // {cost, vertex}
    int d[v + 1];
    int pre[v + 1];
    fill(d, d + v + 1, INF);

    while (e--) {
        int u, v, w;
        cin >> u >>  v >> w;
        cost[u].emplace_back(w, v);
    }

    int start, end;
    cin >> start >> end;

    d[start] = 0;
    priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<>
    > pq;
    pq.push({d[start], start});

    while (!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();

        if (d[cur.Y] != cur.X)
            continue;

        for (auto &nxt : cost[cur.Y]) {
            if (d[nxt.Y] <= d[cur.Y] + nxt.X)
                continue;

            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({d[nxt.Y], nxt.Y});
            pre[nxt.Y] = cur.Y;
        }
    }

    cout << d[end] << '\n';
    vector<int> path;
    int cur = end;
    while (cur != start) {
        path.push_back(cur);
        cur = pre[cur];
    }
    path.push_back(cur);
    reverse(path.begin(), path.end());

    cout << path.size() << '\n';
    for (auto &x : path)
        cout << x << ' ';
}
