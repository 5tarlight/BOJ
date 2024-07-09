#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int graph[n + 1][m + 1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> graph[i][j];
    int k;
    cin >> k;
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1e9;
    for (int i = 0; i <= m; i++)
        dp[0][i] = 1e9;

    dp[1][0] = dp[0][1] = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + graph[i][j];

    if (dp[n][m] > k) {
        cout << "NO";
    } else {
        cout << "YES\n";
        cout << dp[n][m];
    }
}
