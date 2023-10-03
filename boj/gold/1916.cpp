#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

#define X first
#define Y second
#define INF 1'000'000

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, start, end;
    cin >> n >> m;
    vector<pair<int, int>> graph[n + 1]; // {cost, index}
    int d[n + 1];
    fill(d, d + n + 1, INF);

    while (m--) {
        int s, e, c;
        cin >> s >> e >> c;
        graph[s].push_back({c, e});
    }
    cin >> start >> end;
    d[start] = 0;

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<>
    > pq;
    pq.push({d[start], start});

    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        if (d[cur.Y] != cur.X)
            continue;

        for (auto &nxt : graph[cur.Y]) {
            if (d[nxt.Y] <= d[cur.Y] + nxt.X)
                continue;

            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({d[nxt.Y], nxt.Y});
        }
    }

    cout << d[end];
}
