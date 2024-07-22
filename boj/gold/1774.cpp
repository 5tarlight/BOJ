#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstdio>

using namespace std;

int parents[1001];

int find(int x) {
    if (parents[x] == x) return x;
    else return parents[x] = find(parents[x]);
}

void unite(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    if (pa != pb)
        parents[pa] = pb;
}

int n, m;
pair<long long, long long> loc[1000];

double getDist(int a, int b) {
    long long dx = loc[a].first - loc[b].first;
    long long dy = loc[a].second - loc[b].second;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        parents[i] = i;
    for (int i = 0; i < n; i++)
        cin >> loc[i].first >> loc[i].second;

    priority_queue<
        pair<double, pair<int, int>>,
        vector<pair<double, pair<int, int>>>,
        greater<>
    > pq;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            pq.push({ getDist(i, j), {  i + 1, j + 1 }});

    while (m--) {
        int a, b;
        cin >> a >> b;
        unite(a, b);
    }

    double ans = 0;
    while (!pq.empty()) {
        auto [cost, p] = pq.top();
        auto [a, b] = p;
        pq.pop();

        if (find(a) == find(b))
            continue;

        ans += cost;
        unite(a, b);
    }

    printf("%.2f", ans);
}
