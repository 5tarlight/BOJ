#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int dp[n + 1];

    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (i % 6 == 0)
            dp[i] = min(min(dp[i / 3], dp[i - 1]), dp[i / 2]) + 1;
        else if (i % 3 == 0)
            dp[i] = min(dp[i / 3], dp[i - 1]) + 1;
        else if (i % 2 == 0)
            dp[i] = min(dp[i / 2], dp[i - 1]) + 1;
        else
            dp[i] = dp[i - 1] + 1;
    }

    cout << dp[n];
}
