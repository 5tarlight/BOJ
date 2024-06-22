#include <iostream>

using namespace std;

int n, l, r;
int dp[101][101][101];
const int MOD = 1e9 + 7;

#define loop(i, l, r) for (int i = l; i <= r; i++)

int main() {
    cin >> n >> l >> r;
    dp[1][1][1] = 1;

    loop(i, 2, n)
        loop(j, 1, l)
            loop(k, 1, r)
                dp[i][j][k] = (
                        (long long)dp[i - 1][j][k] * (i - 2)
                        + dp[i - 1][j][k - 1]
                        + dp[i - 1][j - 1][k]
                ) % MOD;

    cout << dp[n][l][r];
}
