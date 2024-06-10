#include <iostream>

using namespace std;

#define DIV 1000000

int dp[1001][2][3];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    dp[1][0][0] = dp[1][1][0] = dp[1][0][1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i][0][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % DIV;
        dp[i][0][1] = dp[i - 1][0][0] % DIV;
        dp[i][0][2] = dp[i - 1][0][1] % DIV;
        dp[i][1][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2] +
                dp[i - 1][1][0] + dp[i - 1][1][1] + dp[i - 1][1][2]) % DIV;
        dp[i][1][1] = dp[i - 1][1][0] % DIV;
        dp[i][1][2] = dp[i - 1][1][1] % DIV;
    }

    int ans = (dp[n][0][0] + dp[n][0][1] + dp[n][0][2]
            + dp[n][1][0] + dp[n][1][1] + dp[n][1][2]) % DIV;

    cout << ans;
}
