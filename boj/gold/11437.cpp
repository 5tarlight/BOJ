#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int parents[50001];
int depth[50001];
vector<int> graph[50001];
int n;

int lca(int a, int b) {
    if (depth[a] < depth[b])
        swap(a, b);

    while (depth[a] != depth[b])
        a = parents[a];

    while (a != b) {
        a = parents[a];
        b = parents[b];
    }

    return a;
}

void init(int node, int p) {
    parents[node] = p;
    depth[node] = depth[p] + 1;

    for (int i = 0; i < graph[node].size(); i++) {
        if (p == graph[node][i])
            continue;
        init(graph[node][i], node);
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    init(1, 0);

    int m;
    cin >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
}
