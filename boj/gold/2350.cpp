#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
const int LOGN = 11;
const int INF = 1e9;

struct dsu {
    vector<int> p, r;
    dsu(int n): p(n + 1), r(n + 1, 0) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (r[a] < r[b]) swap(a, b);
        p[b] = a;
        if (r[a] == r[b]) r[a]++;
        return true;
    }
};

int n, m, k;
struct edge { int u, v, w; };
vector<edge> e;
vector<pair<int, int>> g[MAXN];
int d[MAXN];
int par[LOGN][MAXN];
int mn[LOGN][MAXN];

void dfs(int u, int p, int w) {
    par[0][u] = p;
    mn[0][u] = (p == 0 ? INF : w);
    for (auto &[v, wt] : g[u]) {
        if (v == p) continue;
        d[v] = d[u] + 1;
        dfs(v, u, wt);
    }
}

int query(int u, int v) {
    if (u == v) return INF;
    int res = INF;
    if (d[u] < d[v]) swap(u, v);
    int diff = d[u] - d[v];
    for (int i = 0; i < LOGN; i++) {
        if (diff & (1 << i)) {
            res = min(res, mn[i][u]);
            u = par[i][u];
        }
    }
    if (u == v) return res;
    for (int i = LOGN - 1; i >= 0; i--) {
        if (par[i][u] != par[i][v]) {
            res = min(res, mn[i][u]);
            res = min(res, mn[i][v]);
            u = par[i][u];
            v = par[i][v];
        }
    }
    res = min(res, mn[0][u]);
    res = min(res, mn[0][v]);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    e.resize(m);
    for (int i = 0; i < m; i++)
        cin >> e[i].u >> e[i].v >> e[i].w;

    sort(e.begin(), e.end(), [](auto &a, auto &b) {
        return a.w > b.w;
    });

    dsu uf(n);
    int cnt = 0;
    for (auto &[u, v, w] : e) {
        if (uf.unite(u, v)) {
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
            if (++cnt == n - 1) break;
        }
    }

    d[1] = 0;
    dfs(1, 0, INF);

    for (int i = 1; i < LOGN; i++) {
        for (int v = 1; v <= n; v++) {
            par[i][v] = par[i - 1][par[i - 1][v]];
            mn[i][v] = min(mn[i - 1][v], mn[i - 1][par[i - 1][v]]);
        }
    }

    while (k--) {
        int u, v;
        cin >> u >> v;
        cout << query(u, v) << "\n";
    }
}
