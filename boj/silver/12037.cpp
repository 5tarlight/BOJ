#include <iostream>

#define DIV 1000000007

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int j = 1; j <= t; j++) {
        int c, v, l;
        cin >> c >> v >> l;
        int dp[l][2]; // 0: consonant, 1: vowel
        dp[0][0] = c;
        dp[0][1] = v;

        for (int i = 1; i < l; i++) {
            dp[i][0] = dp[i - 1][1] * c % DIV;
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) * v % DIV;
        }

        cout << "Case #" << j << ": " << dp[l - 1][1] << '\n';
    }
}
