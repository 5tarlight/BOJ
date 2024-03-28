#include <iostream>
#include <algorithm>

#define DIV 10007

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    k = min(k, n - k);

    int dp[1001][1001] = {0, };
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
        dp[i][i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % DIV;
        }
    }
    cout << dp[n][k] << '\n';
}
