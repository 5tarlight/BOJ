#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 0;

    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0)
            dp[i] = dp[i / 2] + dp[i / 2] + (i / 2) * (i / 2);
        else
            dp[i] = dp[i / 2] + dp[i / 2 + 1] + (i / 2) * (i / 2 + 1);
    }

    cout << dp[n];
}
