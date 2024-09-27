#include "bits/stdc++.h"

using namespace std;

constexpr int DIV = 1e9 + 9;

int dp[100001][2];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[2][0] = 1;
    dp[3][1] = 2;
    dp[3][0] = 2;

    for (int i = 4; i <= 100000; i++) {
        for (int j = 1; j <= 3; j++) {
            dp[i][1] += dp[i - j][0];
            dp[i][1] %= DIV;
            dp[i][0] += dp[i - j][1];
            dp[i][0] %= DIV;
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << dp[n][1] << ' ' << dp[n][0] << '\n';
    }
}
