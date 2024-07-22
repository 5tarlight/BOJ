#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long dp[n + 1];
    dp[2] = 1;
    dp[3] = 2;

    for (int i = 4; i <= n; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) * (i - 1) % 1'000'000'000;

    cout << dp[n];
}
