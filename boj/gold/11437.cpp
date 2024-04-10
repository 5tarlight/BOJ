#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> p;

vector<int> adj[100001];
int n;
int parent[100001];
int depth[100001];

int lca(int a, int b) {
    if (depth[a] < depth[b])
        swap(a, b);

    while (depth[a] != depth[b])
        a = parent[a];

    while (a != b) {
        a = parent[a];
        b = parent[b];
    }

    return a;
}

void init(int node, int pp) {
    parent[node] = pp;
    depth[node] = depth[pp] + 1;

    for (int i = 0; i < adj[node].size(); i++) {
        int next = adj[node][i];
        if (next == pp) continue;
        init(next, node);
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
        adj[a].push_back(b);
        adj[b].push_back(a);
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
