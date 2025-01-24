#include "bits/stdc++.h"

using namespace std;

constexpr int MOD = 1e9 + 7;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    long long dp[5001] = {0};
    dp[0] = 1;
    for (int i = 2; i <= 5000; i += 2) {
        for (int j = 2; j <= i; j += 2) {
            dp[i] += dp[j - 2] * dp[i - j];
            dp[i] %= MOD;
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        cout << dp[x] << '\n';
    }
}
