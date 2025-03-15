#include "bits/stdc++.h"

using namespace std;

int n, m;
int dp[10001][500];
bool ok[10001];

int solve(int idx, int prev) {
    if (idx == n) return 0;
    if (idx > n || !ok[idx]) return 1e9;
    if (dp[idx][prev] != -1) return dp[idx][prev];

    int ans = 1e9;

    if (prev - 1 > 0 && idx + prev - 1 <= n && ok[idx + prev - 1])
        ans = min(ans, solve(idx + prev - 1, prev - 1) + 1);
    if (prev > 0 && idx + prev <= n && ok[idx + prev])
        ans = min(ans, solve(idx + prev, prev) + 1);
    if (idx + prev + 1 <= n && ok[idx + prev + 1])
        ans = min(ans, solve(idx + prev + 1, prev + 1) + 1);

    return dp[idx][prev] = ans;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    memset(ok, true, sizeof(ok));

    while (m--) {
        int x;
        cin >> x;
        ok[x] = false;
    }

    int ans = solve(1, 0);

    if (ans == 1e9) cout << -1;
    else cout << ans;
}
