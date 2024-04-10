#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef pair<int, int> p;

vector<int> adj[100001];
int n;
int parent[100001][18];
int depth[100001];
int maxD = (int)floor(log2(100001));

void init(int node, int pp, int d) {
    depth[node] = d;
    parent[node][0] = pp;

    for (int i = 1; i <= maxD; i++)
        parent[node][i] = parent[parent[node][i - 1]][i - 1];

    for (int i = 0; i < adj[node].size(); i++) {
        int next = adj[node][i];
        if (next == pp) continue;
        init(next, node, d + 1);
    }
}

int lca(int a, int b) {
    if (a == 1 || b == 1) return 1;

    int target = a;
    int cmp = b;
    if (depth[a] < depth[b])
        swap(target, cmp);

    if (depth[target] != depth[cmp]) {
        for (int i = maxD; i >= 0; i--) {
            if (depth[parent[target][i]] >= depth[cmp])
                target = parent[target][i];
        }
    }

    int ans = target;
    if (target != cmp) {
        for (int i = maxD; i >= 0; i--) {
            if (parent[target][i] != parent[cmp][i]) {
                target = parent[target][i];
                cmp = parent[cmp][i];
            }
            ans = parent[target][i];
        }
    }

    return ans;
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

    init(1, 0, 1);

    int m;
    cin >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
}
