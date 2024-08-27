#include <iostream>
#include <cmath>

using namespace std;

#define MOD 1000000007
long long dp[1000][26];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    for (int i = 0; i < 26; i++)
        dp[0][i] = 1;

    cin >> n >> m;

    for (int i = 1; i < m; i++) {
        for (int j = 0; j < 26; j++) {
            for (int k = 0; k < 26; k++) {
                if (abs(j - k) < n)
                    continue;
                dp[i][j] += dp[i - 1][k];
                dp[i][j] %= MOD;
            }
        }
    }

    int ans = 0;
    for (auto v : dp[m - 1]) {
        ans += v;
        ans %= MOD;
    }

    cout << ans;
}
