#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    long long dp[n + 1];

    if (n == 2) {
        cout << 3;
        return 0;
    } else if (n & 1) {
        cout << 0;
        return 0;
    }

    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;
    dp[3] = 0;

    for (int i = 4; i <= n; i++) {
        if (i & 1) {
            dp[i] = 0;
            continue;
        }

        dp[i] = dp[i - 2] * 3;
        for (int j = i - 4; j >= 0; j -= 2) {
            dp[i] += dp[j] * 2;
        }
    }

    cout << dp[n];
}
