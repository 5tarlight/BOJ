#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int parents[200001];

int find(int x) {
    if (parents[x] == x)
        return x;
    return parents[x] = find(parents[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y)
        parents[y] = x;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        parents[i] = i;

    priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<>
    > pq;

    while (m--) {
        int k, c;
        cin >> k >> c;
        int edges[k];
        for (int i = 0; i < k; i++)
            cin >> edges[i];

        int min_node = *min_element(edges, edges + k);
        for (int node : edges) {
            if (node != min_node) {
                pq.push({c, {min_node, node}});
            }
        }
    }

    // MST
    long long answer = 0;
    int cnt = 0;
    while (!pq.empty()) {
        auto [cost, edge] = pq.top();
        pq.pop();

        if (find(edge.first) != find(edge.second)) {
            merge(edge.first, edge.second);
            answer += cost;
            cnt++;
        }
    }

    // Check if all nodes are connected
    if (cnt != n - 1)
        cout << -1;
    else
        cout << answer;
}
