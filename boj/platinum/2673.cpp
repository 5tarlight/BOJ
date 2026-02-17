#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    int n; cin >> n;
    int dp[101][101], cost[101][101];
    memset(dp, 0, sizeof(dp));
    memset(cost, 0, sizeof(cost));

    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        cost[x][y] = cost[y][x] = 1;
    }

    for (int i = 1; i <= 100; i++)
        for (int j = i; j >= 1; j--)
            for (int k = j; k < i; k++)
                dp[j][i] = max(
                   dp[j][i],
                   dp[j][k] + dp[k][i] + cost[i][j]
                );

    cout << dp[1][100];
}
