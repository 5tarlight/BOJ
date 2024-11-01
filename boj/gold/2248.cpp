#include "bits/stdc++.h"

using namespace std;

long long n, l, m;
long long dp[32][32];

long long sol(int i, int j) {
    if (j == l || i >= n) return 1;
    if (dp[i][j]) return dp[i][j];
    return dp[i][j] = sol(i + 1, j) + sol(i + 1, j + 1);
}

int main() {
    cin >> n >> l >> m;
    for (int i = 1, j = 0; i <= n; i++) {
        if (sol(i, j) >= m)
            cout << 0;
        else {
            cout << 1;
            m -= sol(i, j);
            j++;
        }
    }
}
