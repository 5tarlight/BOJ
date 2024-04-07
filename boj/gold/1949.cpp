#include <iostream>
#include <vector>

using namespace std;

int n;
int dp[10001][2];
int population[10001];
bool visited[10001];
vector<int> tree[10001];

void dfs(int node) {
    visited[node] = true;

    dp[node][0] = 0;
    dp[node][1] = population[node];

    for (int i = 0; i < tree[node].size(); i++) {
        int next = tree[node][i];

        if (visited[next]) continue;

        dfs(next);

        dp[node][0] += max(dp[next][0], dp[next][1]);
        dp[node][1] += dp[next][0];
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> population[i];
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1);

    cout << max(dp[1][0], dp[1][1]);
}
