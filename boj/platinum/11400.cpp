#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

constexpr int MAX = 100001;

int v, e;
vector<int> adj[MAX];
int visited[MAX];
vector<pair<int, int>> ans;

int dfs(int p, int s, int o) {
    int ret = o;
    visited[s] = o;

    for (int i = 0; i < adj[s].size(); i++) {
        int next = adj[s][i];
        if (next == p) continue;
        if (visited[next] == 0) {
            int nxto = dfs(s, next, o + 1);
            if (nxto > visited[s])
                ans.push_back({ min(s, next), max(s, next) });
            ret = min(ret, nxto);
        } else {
            ret = min(ret, visited[next]);
        }
    }

    return ret;
}

int main() {
    fio();

    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= v; i++)
        sort(adj[i].begin(), adj[i].end());

    for (int i = 1; i <= v; i++)
        if (visited[i] == 0)
            dfs(0, i, 1);

    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
}
