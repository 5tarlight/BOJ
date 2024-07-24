#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int abs(int a) {
    return (a < 0) ? -a : a;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int d, n;
    cin >> d >> n;
    int t[d];
    for (int i = 0; i < d; i++)
        cin >> t[i];
    pair<int, int> temp[n];
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> temp[i].first >> temp[i].second >> a[i];

    int dp[d][n];
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n; i++) {
        if (t[0] >= temp[i].first && t[0] <= temp[i].second) {
            dp[0][i] = 0;
        }
    }

    for (int day = 1; day < d; day++) {
        for (int i = 0; i < n; i++) {
            if (t[day] >= temp[i].first && t[day] <= temp[i].second) {
                for (int j = 0; j < n; j++) {
                    if (dp[day - 1][j] != -1 && t[day - 1] >= temp[j].first && t[day - 1] <= temp[j].second) {
                        dp[day][i] = max(dp[day][i], dp[day - 1][j] + abs(a[i] - a[j]));
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[d - 1][i]);
    }

    cout << ans;

    return 0;
}
