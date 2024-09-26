#include "bits/stdc++.h"

using namespace std;

int n, m;
vector<int> graph[100001];
vector<int> tree[100001];
int depth[100001];
int p[100001][18];

void init(int cur) {
    for (int nxt : graph[cur]) {
        if (depth[cur] == -1) {
            depth[nxt] = depth[cur] + 1;
            p[nxt][0] = cur;
            init(nxt);
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    int diff = depth[u] - depth[v];
    for (int j = 0; diff; j++) {
        if (diff % 2) u = p[u][j];
        diff /= 2;
    }

    if (u != v) {
        for (int j = 17; j >= 0; j--) {
            if (p[u][j] != -1 && p[u][j] != p[v][j]) {
                u = p[u][j];
                v = p[v][j];
            }
        }

        u = p[u][0];
    }

    return u;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    memset(depth, -1, sizeof(depth));
    memset(p, -1, sizeof(p));
    depth[1] = 0;
    init(1);

    for (int j = 0; j < 18; j++)
        for (int i = 1; i <= n; i++)
            if (p[i][j] != -1)
                p[i][j + 1] = p[p[i][j]][j];

    cin >> m;
    while (m--) {
        int r, u, v;
        cin >> r >> u >> v;

        int rr = r;
        int uu = u;
        int vv = v;

        int uv = lca(u, v);
        u = uu; v = vv;
        int ur = lca(u, r);
        u = uu; r = rr;
        int vr = lca(v, r);
        v = vv; r = rr;

        int ans = uv;
        ans = depth[ans] > depth[ur] ? ans : ur;
        ans = depth[ans] > depth[vr] ? ans : vr;

        cout << ans << '\n';
    }
}
