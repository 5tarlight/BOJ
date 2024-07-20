#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();
    int dp[n][n];
    const int mod = 10007;

    for (int i = 0; i < n; i++)
        dp[i][i] = 1;
    for (int i = 1; i < n; i++) {
        dp[i - 1][i] = 2;
        if (s[i] == s[i - 1])
            dp[i - 1][i]++;
    }
    for (int i = 2; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (s[j] == s[j - i])
                dp[j - i][j] = (dp[j - i][j - 1] + dp[j - i + 1][j] + 1) % mod;
            else
                dp[j - i][j] = (mod + dp[j - i][j - 1] + dp[j - i  + 1][j] - dp[j - i + 1][j - 1]) % mod;
        }
    }

    cout << dp[0][n - 1];
}
