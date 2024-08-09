#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int a[n + 1][m + 1], dp[n + 1][m + 1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dp[i][j] = max({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] }) + a[i][j];

    cout << dp[n][m];
}
