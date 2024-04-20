#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int t[n + 1];
    int p[n + 1];
    t[n] = p[n] = 0;
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> p[i];
    }

    int dp[n + 1];
    fill(dp, dp + n + 1, 0);
    int ans = 0;

    for (int i = 0; i <= n; i++) {
        dp[i] = max(dp[i], ans);

        if (i + t[i] <= n) {
            dp[i + t[i]] = max(dp[i + t[i]], dp[i] + p[i]);
        }

        ans = max(ans, dp[i]);
    }

    cout << ans;
}
