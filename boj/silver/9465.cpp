#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int nums[2][n];

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                cin >> nums[i][j];
            }
        }

        int dp[2][n];
        dp[0][0] = nums[0][0];
        dp[1][0] = nums[1][0];

        for (int i = 1; i < n; i++) {
            dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + nums[0][i]);
            dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] + nums[1][i]);
        }

        cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
    }
}
