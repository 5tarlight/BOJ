#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    int dp[n];
    dp[0] = 1;
    dp[1] = 3;

    for (int i = 2; i < n; i++) {
        dp[i] = (dp[i - 2] * 2 + dp[i - 1]) % 10007;
    }

    cout << dp[n - 1];
}
