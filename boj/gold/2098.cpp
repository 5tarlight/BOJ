#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define INF 987654321

int n;
int graph[16][16];
int dp[16][1 << 16];

int dfs(int cur, int visited) {
    if (visited == (1 << n) - 1) {
        if (graph[cur][0] == 0)
            return INF;
        return graph[cur][0];
    }
    if (dp[cur][visited] != -1)
        return dp[cur][visited];

    dp[cur][visited] = INF;

    for (int i = 0; i < n; i++) {
        if (graph[cur][i] == 0 || (visited & (1 << i)) != 0)
            continue;

        dp[cur][visited] = min(dp[cur][visited], graph[cur][i] + dfs(i, visited | (1 << i)));
    }

    return dp[cur][visited];
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    memset(dp, -1, sizeof(dp));

    cout << dfs(0, 1);
}
