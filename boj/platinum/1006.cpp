#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define INF 1e9

int a[2][10001];
int dp[10001][3];
int n, w;

void update() {
    for (int i = 2; i <= n; i++) {
        int u = a[0][i - 1] + a[0][i] <= w ? 1 : 2;
        int d = a[1][i - 1] + a[1][i] <= w ? 1 : 2;
        int v = a[0][i] + a[1][i] <= w ? 1 : 2;

        dp[i][0] = min({
            dp[i - 1][0] + v,
            dp[i - 2][0] + u + d,
            dp[i - 1][1] + u + 1,
            dp[i - 1][2] + d + 1
        });
        dp[i][1] = min(dp[i - 1][2] + d, dp[i - 1][0] + 1);
        dp[i][2] = min(dp[i - 1][1] + u, dp[i - 1][0] + 1);
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        memset(dp, 0, sizeof(dp));
        cin >> n >> w;

        for (int i = 0; i < 2; i++)
            for (int j = 1; j <= n; j++)
                cin >> a[i][j];

        int u = a[0][1];
        int d = a[1][1];
        int ans = INF;

        dp[1][0] = a[0][1] + a[1][1] <= w ? 1 : 2;
        dp[1][1] = dp[1][2] = 1;
        update();
        ans = min(ans, dp[n][0]);

        if (a[0][1] + a[0][n] <= w) {
            dp[1][0] = 2;
            dp[1][1] = dp[1][2] = 1;
            a[0][1] = INF;
            update();
            ans = min(ans, dp[n][1]);
            a[0][1] = u;
        }

        if (a[1][1] + a[1][n] <= w) {
            dp[1][0] = 2;
            dp[1][1] = dp[1][2] = 1;
            a[1][1] = INF;
            update();
            ans = min(ans, dp[n][2]);
            a[1][1] = d;
        }

        if (a[0][1] + a[0][n] <= w && a[1][1] + a[1][n] <= w) {
            a[0][1] = a[1][1] = INF;
            dp[1][0] = 2;
            dp[1][1] = dp[1][2] = 1;
            update();
            ans = min(ans, dp[n - 1][0]);
            a[0][1] = u;
            a[1][1] = d;
        }

        if (n == 1)
            ans = a[0][1] + a[1][1] <= w ? 1 : 2;

        cout << ans << '\n';
    }
}
