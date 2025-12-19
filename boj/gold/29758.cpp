#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int sum[16][70001];
int dp[16][70001];

int main() {
    fio();

    memset(dp, 0, sizeof(dp));
    memset(sum, 0, sizeof(sum));

    dp[1][1] = 1;
    for (int j = 1; j <= 70000; j++)
        sum[1][j] = 1;

    for (int i = 2; i <= 15; i++) {
        for (int j = 1; j <= 70000; j++) {
            int l = floor(sqrt(j - 1));

            if (l >= 1)
                dp[i][j] = sum[i - 1][l];
            sum[i][j] = (sum[i][j - 1] + dp[i][j]) % 1000000007;
        }
    }

    int t; cin >> t;
    while (t--) {
        int n, l; cin >> n >> l;

        if (l > 15)
            cout << "0\n";
        else
            cout << dp[l][n] << "\n";
    }
}
