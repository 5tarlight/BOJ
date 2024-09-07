#include "bits/stdc++.h"

using namespace std;

using ll = long long;

ll cache[2001][2001]; // iCj
int m;

vector<ll> luca(ll val, ll mod) {
    vector<ll> ans;

    while (val) {
        int r = val % mod;
        ans.push_back(r);
        val /= mod;
    }

    return ans;
}

ll comb(int n, int r) {
    if (n < r) return 0;
    if (n / 2 < r) r = n - r;

    ll &ans = cache[n][r];
    if (ans != -1) return ans;

    if (r == 0) return ans = 1;
    else if (r == 1) return ans = n;

    return ans = (comb(n - 1, r - 1) + comb(n - 1, r)) % m;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    memset(cache, -1, sizeof(cache));

    ll n, k;
    cin >> n >> k >> m;

    auto l1 = luca(n, m);
    auto l2 = luca(k, m);

    ll ans = 1;
    int to = min(l1.size(), l2.size());
    for (int i = 0; i < to; i++) {
        int n = l1[i];
        int r = l2[i];

        ans = ans * comb(n, r) % m;
    }

    cout << ans;
}
