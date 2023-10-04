#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define INF 1'000'000'000
#define COST first
#define INDEX second

int n, m, x;
vector<pair<int, int>> graph[2][1001]; // cost, index
vector<int> d[2];

void dijkstra(int k) {
    d[k][x] = 0;

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<>
    > pq;
    pq.emplace(0, x);

    while (!pq.empty()) {
        int cost = pq.top().COST;
        int index = pq.top().INDEX;
        pq.pop();

        if (cost != d[k][index])
            continue;

        for (int i = 0; i < graph[k][index].size(); i++) {
            int nexti = graph[k][index][i].INDEX;
            int nextc = graph[k][index][i].COST + cost;

            if (nextc < d[k][nexti]) {
                d[k][nexti] = nextc;
                pq.emplace(nextc, nexti);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> x;
    while (m--) {
        int a, b, di;
        cin >> a >> b >> di;
        graph[0][a].emplace_back(di, b);
        graph[1][b].emplace_back(di, a);
    }
    d[0].resize(n + 1, INF);
    d[1].resize(n + 1, INF);

    dijkstra(1); // n -> x
    dijkstra(0); // x -> n

    int ma = -1;
    for (int i = 1; i <= n; i++) {
        if (d[0][i] + d[1][i] > ma)
            ma = d[0][i] + d[1][i];
    }

    cout << ma;
}
