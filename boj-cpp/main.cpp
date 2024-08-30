#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t, w;
    cin >> t >> w;
    int dp[w + 1][t + 1];
    int pos[t];
    for (int i = 0; i < t; i++) cin >> pos[i];

    dp[1][0] = pos[1] % 2;
    dp[1][1] = pos[1] / 2;

    for (int i = 2; i <= t; i++) {
        for (int j = 0; j <= w; j++) {
            int tmp = w % 2 == 0 ? pos[t] % 2 : pos[t];

            for ()
        }
    }
}
