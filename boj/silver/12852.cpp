#include <iostream>
#include <algorithm>

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
        if (i % 6 == 0)
            dp[i] = min(dp[i / 3], min(dp[i / 2], dp[i - 1])) + 1;
        else if (i % 3 == 0)
            dp[i] = min(dp[i / 3], dp[i - 1]) + 1;
        else if (i % 2 == 0)
            dp[i] = min(dp[i / 2], dp[i - 1]) + 1;
        else
            dp[i] = dp[i - 1] + 1;
    }

    cout << dp[n] << '\n';

    while (n != 1) {
        cout << n << ' ';

        if (n % 3 == 0 && dp[n] == dp[n / 3] + 1)
            n /= 3;
        else if (n % 2 == 0 && dp[n] == dp[n / 2] + 1)
            n /= 2;
        else
            n--;
    }
    cout << 1;
}
