#include "bits/stdc++.h"

using namespace std;

constexpr int MOD = 1000000000;
int dp[5001][5001];

int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i <= n; i++)
        dp[i][1] = 1;

    for (int j = 2; j <= k; j++) {
        for (int i = 0; i <= n; i++) {
            dp[i][j] = (i > 0 ? dp[i - 1][j] : 0) + dp[i][j - 1];
            dp[i][j] %= MOD;
        }
    }

    cout << dp[n][k] << '\n';
}