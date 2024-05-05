#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int parents[1001];

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

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
        parents[i] = i;


    vector<int> v;
    while (k--) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    for (int i = 0; i < v.size() - 1; i++)
        merge(v[i], v[i + 1]);

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        pq.push({c, {a, b}});
    }

    int answer = 0;
    while (!pq.empty()) {
        auto [cost, edge] = pq.top();
        pq.pop();
        auto [a, b] = edge;
        if (find(a) == find(b)) continue;
        merge(a, b);
        answer += cost;
    }

    cout << answer;
}
