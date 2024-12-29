#include "bits/stdc++.h"

using namespace std;

constexpr int DIV = 1e9 + 7;
int dp[10000001];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    dp[0] = 1;
    dp[1] = 4;
    for (int i = 2; i <= 10000000; i++) {
        dp[i] = dp[i - 1] * 5L % DIV;
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << "5\n";
            continue;
        }

        cout << dp[n] << '\n';
    }
}
