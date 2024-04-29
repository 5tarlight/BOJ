#include <iostream>
#include <algorithm>

using namespace std;

int n, t;
int dp[1001][1001];
int day[1001];
int cost[1001];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> t;
    int totalCost = 0;

    for (int i = 1; i <= n; i++) {
        cin >> day[i] >> cost[i];
        totalCost += cost[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= t; j++) {
            if (j >= day[i])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - day[i]] + cost[i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << totalCost - dp[n][t];
}
