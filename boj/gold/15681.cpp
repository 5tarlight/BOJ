#include <iostream>
#include <vector>

using namespace std;

int n, r, q;
vector<int> tree[100001];
int dp[100001];
bool visited[100001];

int dfs(int target) {
    visited[target] = true;

    for (int i = 0; i < tree[target].size(); i++) {
        int next = tree[target][i];
        if (visited[next]) continue;
        dp[target] += dfs(next);
    }

    return dp[target];
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> r >> q;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
    }

    dfs(r);

    for (int i = 0; i < q; i++) {
        int target;
        cin >> target;
        cout << dp[target] << '\n';
    }
}
