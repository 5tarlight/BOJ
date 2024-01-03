#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int dp[n];
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        int m = 0;
        for (int j = 0; j < i; j++) {
            if (a[j] > a[i] && m < dp[j])
                m = dp[j];
        }
        dp[i] = m + 1;
    }

    int ans = -1;
    for (int i = 0; i < n; i++)
        if (dp[i] > ans)
            ans = dp[i];

    cout << ans;
}
