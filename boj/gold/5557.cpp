#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    long long dp[n][21];
    memset(dp, 0, sizeof(dp));
    dp[0][a[0]] = 1;

    for (int i = 1; i < n - 1; i++) {
        int cur = a[i];
        for (int j = 0; j <= 20; j++) {
            if (j + cur <= 20)
                dp[i][j + cur] += dp[i - 1][j];
            if (j - cur >= 0)
                dp[i][j - cur] += dp[i - 1][j];
        }
    }

     cout << dp[n - 2][a[n - 1]];
}
