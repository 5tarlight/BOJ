#include "bits/stdc++.h"

using namespace std;
using ll = long long;

unordered_map<ll, ll> m;
ll n, p, q;

ll ans(ll x) {
    if (m.find(x) != m.end()) return m[x];
    ll tmp = ans(x / p) + ans(x / q);
    m[x] = tmp;
    return tmp;
}

int main() {
    cin >> n >> p >> q;
    m[0] = 1;
    if (n == 0) cout << 1;
    else cout << ans(n);
}
