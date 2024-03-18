#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int a[n + 1];
    int dp[n + 1];
    fill(dp, dp + n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    dp[1] = a[1];

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] = max(dp[i], dp[i - j] + a[j]);
        }
    }

    cout << dp[n];
}
