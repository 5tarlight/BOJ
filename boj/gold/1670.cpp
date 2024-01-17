#include <iostream>
#include <algorithm>

using namespace std;

#define DIV 987654321

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    long long dp[n + 1];
    fill(dp, dp + n + 1, 0);
    dp[0] = dp[2] = 1;

    for (int i = 4; i <= n; i += 2) {
        for (int j = 2; i >= j; j += 2) {
            dp[i] += dp[j - 2] * dp[i - j];
            dp[i] %= DIV;
        }
    }

    cout << dp[n];
}
