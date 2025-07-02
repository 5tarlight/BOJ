#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

using ll = long long;
const ll INF = 9e18;

int main() {
    fio();

    int n, m;
    cin >> n >> m;
    vector<int> l(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> l[i];

    vector<ll> p(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + l[i];

    vector<ll> dp(n + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            ll used = p[i] - p[j] + i - j - 1;
            if (used > m) break;

            ll cost = i == n ? 0 : (m - used) * (m - used);
            dp[i] = min(dp[i], dp[j] + cost);
        }
    }

    cout << dp[n];
}
