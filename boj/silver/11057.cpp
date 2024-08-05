#include <iostream>

using namespace std;

int dp[1000][10];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i <= 9; i++)
        dp[0][i] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            dp[i][j] = 0;
            for (int k = 0; k <= j; k++) {
                dp[i][j] += dp[i - 1][k];
                dp[i][j] %= 10007;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= 9; i++) {
        ans += dp[n - 1][i];
        ans %= 10007;
    }

    cout << ans;
}
