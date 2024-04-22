#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int dp[n][n];

    for (int i = 0; i < n; i++) {
        int min = a[i];
        int max = a[i];
        for (int j = i; j < n; j++) {
            if (min > a[j])
                min = a[j];
            if (max < a[j])
                max = a[j];

            dp[i][j] = max - min;
        }
    }

    int ans[n];
    for (int i = 0; i < n; i++) {
        ans[i] = dp[0][i];
        for (int j = 0; j < i; j++) {
            if (ans[i] < ans[j] + dp[j + 1][i])
                ans[i] = ans[j] + dp[j + 1][i];
        }
    }

    cout << ans[n - 1];
}
