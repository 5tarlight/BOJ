#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n - 1; i++)
            cin >> a[i] >> b[i];
    int k;
    cin >> k;

    int dp[n][2];
    memset(dp, 0x30, sizeof(dp));
    dp[0][0] = 0;
    dp[1][0] = a[0];
    dp[2][0] = min(dp[1][0] + a[1], b[0]);

    for (int i = 3; i < n; i++) {
        dp[i][0] = min(dp[i - 1][0] + a[i - 1], dp[i - 2][0] + b[i - 2]);
        dp[i][1] = min({dp[i - 3][0] + k, dp[i - 2][1] + b[i - 2], dp[i - 1][1] + a[i - 1]});
    }

    cout << min(dp[n - 1][0], dp[n - 1][1]);
}
