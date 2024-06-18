#include <iostream>

using namespace std;

#define MOD 1000000007

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int dp[3][n + 1];
    dp[0][1] = dp[2][2] = 0;
    dp[0][2] = dp[1][2] = 1;

    for (int i = 3; i < n + 1; i ++) {
        dp[0][i] = (dp[2][i - 1] + dp[1][i - 1]) % MOD;
        dp[1][i] = (dp[0][i - 1] + dp[2][i - 1]) % MOD;
        dp[2][i] = (dp[1][i - 1] + dp[0][i - 1]) % MOD;
    }

    cout << dp[0][n];
}
