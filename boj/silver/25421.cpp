#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    long long dp[n + 1][10]; // [i][j] : i번째가 j
    for (int i = 1; i <= 9; i++)
        dp[1][i] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= 9; j++) {
            dp[i][j] = 0;
            for (int k = -2; k <= 2; k++) {
                if (j + k > 0 && j + k <= 9) {
                    dp[i][j] += dp[i - 1][j + k];
                    dp[i][j] %= 987654321;
                }
            }
        }
    }

    long long ans = 0;
    for (int i = 1; i <= 9; i++) {
        ans += dp[n][i];
        ans %= 987654321;
    }

    cout << ans;
}
