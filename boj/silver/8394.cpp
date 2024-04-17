#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int dp[n - 1][2];
    dp[0][0] = 1;
    dp[0][1] = 1;

    for (int i = 1; i < n - 1; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];

        dp[i][0] %= 10;
        dp[i][1] %= 10;
    }

    cout << (dp[n - 2][0] + dp[n - 2][1]) % 10;
}
