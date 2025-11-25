#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    int h, y;
    cin >> h >> y;
    long long dp[y + 1];
    dp[0] = h;

    for (int i = 1; i <= y; i++) {
        dp[i] = (long long)((double)dp[i - 1] * 1.05);

        if (i >= 3)
            dp[i] = max(dp[i], (long long)((double)dp[i - 3] * 1.2));
        if (i >= 5)
            dp[i] = max(dp[i], (long long)((double)dp[i - 5] * 1.35));
    }

    cout << dp[y];
}
