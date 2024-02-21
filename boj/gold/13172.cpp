#include <iostream>
#include <numeric>

using namespace std;

typedef long long ll;
#define MOD 1000000007

ll modular(ll x, ll y) {
    if (y == 1)
        return x;
    else if (y % 2 == 1)
        return x * modular(x, y - 1) % MOD;
    else {
        ll k = modular(x, y / 2);
        return k * k % MOD;
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll t, a, b;
    ll ans = 0;
    cin >> t;

    while (t--) {
        cin >> b >> a;
        ll k  = gcd(a, b);
        b /= k;
        a /= k;
        ans += a * modular(b, MOD - 2) % MOD;
        ans %= MOD;
    }

    cout << ans;
}
