#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int dp[n][n][3];
    memset(dp, 0, sizeof(dp));
    bool ok[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> ok[i][j];
            ok[i][j] = !ok[i][j];
        }
    }

    // 0 : -, 1 : \, 2 : |
    dp[0][1][0] = 1;

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            if (!ok[i][j]) continue;
            for (int k = 0; k < 3; k++) {
                if (dp[i][j][k]) continue;

                if (k == 0) {
                    if (j - 1 >= 0 && ok[i][j - 1]) {
                        dp[i][j][k] += dp[i][j - 1][0];
                        dp[i][j][k] += dp[i][j - 1][1];
                    }
                } else if (k == 1) {
                    if (j - 1 >= 0 && i - 1 >= 0 && ok[i][j - 1] && ok[i - 1][j]) {
                        if (ok[i][j - 1] && ok[i - 1][j]) {
                            dp[i][j][k] += dp[i - 1][j - 1][0];
                            dp[i][j][k] += dp[i - 1][j - 1][1];
                            dp[i][j][k] += dp[i - 1][j - 1][2];
                        }
                    }
                } else {
                    if (i - 1 >= 0 && ok[i - 1][j]) {
                        dp[i][j][k] += dp[i - 1][j][1];
                        dp[i][j][k] += dp[i - 1][j][2];
                    }
                }
            }
        }
    }

    cout << dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2];
}
