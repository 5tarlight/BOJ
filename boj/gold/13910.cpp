#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int a[m];
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    int dp[n + 1];
    fill(dp, dp + n + 1, 0);

    queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int i = q.front();
        q.pop();

        for (int j = 0; j < m; j++) {
            if (i + a[j] <= n) {
                if (dp[i + a[j]] == 0) {
                    dp[i + a[j]] = dp[i] + 1;
                    q.push(i + a[j]);
                }
            }

            for (int k = j + 1; k < m; k++) {
                if (i + a[j] + a[k] <= n) {
                    if (dp[i + a[j] + a[k]] == 0) {
                        dp[i + a[j] + a[k]] = dp[i] + 1;
                        q.push(i + a[j] + a[k]);
                    }
                }
            }
        }

        if (dp[n] != 0) {
            break;
        }
    }

    if (dp[n] == 0)
        cout << -1;
    else
        cout << dp[n];
}
