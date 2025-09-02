#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<long long> dp(n + 1, 1e9);
    dp[0] = 0;

    int coin[] = { 1, 2, 5, 7 };

    for (int i = 1; i <= n; i++)
        for (int c : coin)
            if (i - c >= 0)
                dp[i] = min(dp[i], dp[i - c] + 1);

    cout << dp[n] << endl;
}
