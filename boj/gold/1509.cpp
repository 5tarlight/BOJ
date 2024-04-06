#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    int l = s.size();
    int dp[l + 1];
    bool pal[l + 1][l + 1];

    // length 1
    for (int i = 1; i <= l; i++) {
        fill(pal[i], pal[i] + l + 1, false);
        pal[i][i] = true;
    }

    // length 2
    for (int i = 1; i < l; i++)
        if (s[i - 1] == s[i])
            pal[i][i + 1] = true;

    // length n
    for (int len = 3; len <= l; len++) {
        for (int st = 1; st + len - 1 <= l; st++) {
            int e = st + len - 1;

            if (s[st - 1] == s[e - 1] && pal[st + 1][e - 1]) {
                pal[st][e] = true;
            }
        }
    }

    dp[0] = 0;
    for (int e = 1; e <= l; e++) {
        dp[e] = 1e9;

        for (int st = 1; st <= e; st++) {
            if (pal[st][e])
                dp[e] = min(dp[e], dp[st - 1] + 1);
        }
    }

    cout << dp[l];
}
