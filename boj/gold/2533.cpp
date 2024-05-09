#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> graph[1000001];
bool visited[1000001];
int dp[1000001][2];

void solve(int x) {
    visited[x] = true;
    dp[x][1] = 1;

    for (int i = 0; i < graph[x].size(); i++) {
        int child = graph[x][i];
        if (visited[child]) continue;

        solve(child);

        dp[x][0] += dp[child][1];
        dp[x][1] += min(dp[child][0], dp[child][1]);
    }
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

    solve(1);
    int ans = min(dp[1][0], dp[1][1]);

    cout << ans;
}
