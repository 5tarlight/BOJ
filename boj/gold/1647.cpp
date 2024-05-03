#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int parents[100001];

int find(int x) {
    if (parents[x] == x) return x;
    return parents[x] = find(parents[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    parents[y] = x;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        parents[i] = i;
    priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<>
    > pq;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        pq.push({c, {a, b}});
    }

    long long total = 0;
    int maxCost = 0;
    while (!pq.empty()) {
        auto [cost, edge] = pq.top();
        pq.pop();

        if (find(edge.first) == find(edge.second))
            continue;

        merge(edge.first, edge.second);

        total += cost;
        maxCost = max(maxCost, cost);
    }

    cout << total - maxCost;
}
