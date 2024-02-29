#include <iostream>

#define MOD 1000000000

// dp[x][y][z] x자리 숫자가 y, 비트는 z
int dp[100][10][1024];
using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 1; i < 10; i++)
        dp[0][i][1 << i] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            for (int bit = 0; bit < 1024; bit++) {
                int t = bit | (1 << j);

                if (j - 1 >= 0)
                    dp[i][j][t] += dp[i - 1][j - 1][bit];
                if (j + 1 <= 9)
                    dp[i][j][t] += dp[i - 1][j + 1][bit];

                dp[i][j][t] %= MOD;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 10; i++) {
        ans += dp[n - 1][i][1023];
        ans %= MOD;
    }

    cout << ans;
}
