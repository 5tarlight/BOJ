#include "bits/stdc++.h"

using namespace std;
using ll = long long;

struct Edge {
    int u, v, w;
};

const int MAX = 50000;
const int LOG = 20;

vector<pair<int, int>> adj[MAX + 1];
vector<Edge> edges;
pair<int, pair<int, int>> lcaParent[MAX + 1][LOG];
int mstParent[MAX + 1], depth[MAX + 1];
bool visited[MAX + 1];
int mst = 0, N, M, cnt = 0;

bool cmp(const Edge& a, const Edge& b) {
    return a.w < b.w;
}

pair<int, int> merge(pair<int, int> a, pair<int, int> b) {
    vector<int> merged = {a.first, a.second, b.first, b.second};
    sort(merged.rbegin(), merged.rend());
    merged.erase(unique(merged.begin(), merged.end()), merged.end());
    if (merged.size() < 2) merged.push_back(-1);
    return {merged[0], merged[1]};
}

void dfs(int node, int d) {
    depth[node] = d;
    visited[node] = true;
    for (auto& [next, weight] : adj[node]) {
        if (visited[next]) continue;
        lcaParent[next][0] = {node, {weight, -1}};
        dfs(next, d + 1);
    }
}

int find(int node) {
    if (mstParent[node] == node) return node;
    return mstParent[node] = find(mstParent[node]);
}

void unionSets(int x, int y, int w) {
    int px = find(x);
    int py = find(y);
    if (px == py) return;
    adj[x].emplace_back(y, w);
    adj[y].emplace_back(x, w);
    mstParent[py] = px;
    mst += w;
    cnt++;
}

void initMst() {
    for (const auto& e : edges) {
        unionSets(e.u, e.v, e.w);
        if (cnt == N - 1) break;
    }
}

void init() {
    iota(mstParent, mstParent + N + 1, 0);
    memset(lcaParent, -1, sizeof(lcaParent));
}

pair<int, int> findLca(int x, int y) {
    if (depth[x] > depth[y]) swap(x, y);
    pair<int, int> ans = {-1, -1};

    for (int i = LOG - 1; i >= 0; i--) {
        if (depth[y] - depth[x] >= (1 << i)) {
            ans = merge(ans, lcaParent[y][i].second);
            y = lcaParent[y][i].first;
        }
    }

    if (x == y) return ans;

    for (int i = LOG - 1; i >= 0; i--) {
        if (lcaParent[x][i].first != 0 && lcaParent[x][i].first != lcaParent[y][i].first) {
            ans = merge(ans, lcaParent[x][i].second);
            ans = merge(ans, lcaParent[y][i].second);
            x = lcaParent[x][i].first;
            y = lcaParent[y][i].first;
        }
    }

    ans = merge(ans, lcaParent[x][0].second);
    ans = merge(ans, lcaParent[y][0].second);

    return ans;
}

void solve() {
    if (cnt < N - 1) {
        cout << "-1\n";
        return;
    }

    dfs(1, 1);
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= N; i++) {
            int parent = lcaParent[i][j - 1].first;
            lcaParent[i][j].first = lcaParent[parent][j - 1].first;
            if (lcaParent[i][j].first == -1) continue;
            lcaParent[i][j].second = merge(lcaParent[i][j - 1].second, lcaParent[parent][j - 1].second);
        }
    }

    ll ans = LLONG_MAX;
    for (const auto& e : edges) {
        auto [x, y, w] = e;
        auto sub = findLca(x, y);

        if (sub.first != w && sub.first != -1)
            ans = min(ans, (ll)(mst - sub.first + w));
        else if (sub.second != w && sub.second != -1)
            ans = min(ans, (ll)(mst - sub.second + w));
    }

    if (ans == LLONG_MAX) cout << "-1\n";
    else cout << ans << '\n';
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        edges.push_back({x, y, w});
    }

    sort(edges.begin(), edges.end(), cmp);

    init();
    initMst();
    solve();

    return 0;
}
