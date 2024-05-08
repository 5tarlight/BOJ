#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string s1, s2;
    cin >> s1 >> s2;
    int l1 = s1.length();
    int l2 = s2.length();
    s1 = " " + s1;
    s2 = " " + s2;
    int dp[l1 + 1][l2 + 1];

    int ans = 0;
    for (int i = 0; i <= l1; i++) {
        for (int j = 0; j <= l2; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (s1[i] == s2[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = 0;
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans;
}
