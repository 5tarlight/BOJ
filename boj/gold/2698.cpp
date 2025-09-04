#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    int dp[101][101][2];
    memset(dp, 0, sizeof(dp));
    dp[1][0][0] = 1;
    dp[1][0][1] = 1;

    for (int i = 2; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
            dp[i][j][1] = dp[i - 1][j][0];

            if (j > 0)
                dp[i][j][1] += dp[i - 1][j - 1][1];
        }
    }

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        cout << dp[n][k][0] + dp[n][k][1] << '\n';
    }
}
