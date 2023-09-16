#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int x;
    cin >> x;
    int dp[x + 1];
    dp[1] = 0;

    for (int i = 2; i <= x; i++) {
        dp[i] = dp[i - 1] + 1;

        if (i % 2 == 0)
            dp[i] = min(dp[i], dp[i / 2] + 1);
        if (i % 3 == 0)
            dp[i] = min(dp[i], dp[i / 3] + 1);
        if (i % 5 == 0)
            dp[i] = min(dp[i], dp[i / 5] + 1);
    }

    cout << dp[x];
}
