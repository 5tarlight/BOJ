#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    int n;
    cin >> n;
    int a[n][3];
    for (int i = 0; i < n; i++)
        cin >> a[i][0] >> a[i][1] >> a[i][2];

    int ans = 1e9;

    for (int first = 0; first < 3; first++) {
        int dp[n][3];
        dp[0][0] = dp[0][1] = dp[0][2] = 1e9;
        dp[0][first] = a[0][first];

        for (int i = 1; i < n; i++) {
            dp[i][0] = a[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
            dp[i][1] = a[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
            dp[i][2] = a[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
        }

        for (int last = 0; last < 3; last++) {
            if (last != first) {
                ans = min(ans, dp[n - 1][last]);
            }
        }
    }

    cout << ans;
}
