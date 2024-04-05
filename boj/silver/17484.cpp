#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int graph[n][m];
    int dp[n][m][3];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];

            if (i == 0)
                for (int k = 0; k < 3; k++)
                    dp[i][j][k] = graph[i][j];
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j][0] = min(dp[i - 1][j][1], dp[i - 1][j][2]) + graph[i][j];

            if (j > 0)
                dp[i][j][1] = min(dp[i - 1][j - 1][0], dp[i - 1][j - 1][2]) + graph[i][j];
            else
                dp[i][j][1] = 1e9;

            if (j < m - 1)
                dp[i][j][2] = min(dp[i - 1][j + 1][0], dp[i - 1][j + 1][1]) + graph[i][j];
            else
                dp[i][j][2] = 1e9;
        }
    }

    int ans = 1e9;
    for (int i = 0; i < m; i++)
        ans = min(ans, min(dp[n - 1][i][0], min(dp[n - 1][i][1], dp[n - 1][i][2])));

    cout << ans;
}
