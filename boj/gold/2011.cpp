#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();

    if (s[0] == '0') {
        cout << 0;
        return 0;
    }

    const int mod = 1000000;
    int dp[n + 1];
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        int one = s[i - 1] - '0';
        int two = one + 10 * (s[i - 2] - '0');

        if (one >= 1 && one <= 9)
            dp[i] = dp[i - 1];
        else
            dp[i] = 0;

        if (two >= 10 && two <= 26)
            dp[i] = (dp[i] + dp[i - 2]) % mod;
    }

    cout << dp[n];
}
