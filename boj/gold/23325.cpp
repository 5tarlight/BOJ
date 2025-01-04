#include "bits/stdc++.h"

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int dp[n];
    fill(dp, dp + n, -1e9);

    dp[0] = s[0] == '+' ? 10 : 1;
    dp[1] = s[1] == '-' && s[0] == '+' ? 11 : dp[1];

    for (int i = 2; i < n; i++) {
        int cur = s[i] == '+' ? 10 : 1;

        if (s[i - 1] == '+')
            dp[i] = dp[i - 2] + cur;
        else
            dp[i] = max(dp[i], dp[i - 2] - cur);

        if (cur == 1 && s[i - 1] == '+' && i > 2) {
            if (s[i - 2] == '+')
                dp[i] = max(dp[i], dp[i - 3] + 11);
            else
                dp[i] = max(dp[i], dp[i - 3] - 11);
        }
    }

    cout << dp[n - 1];
}
