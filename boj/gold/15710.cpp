#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); ios::sync_with_stdio(false); }

using ll = long long;

constexpr ll MOD = 1e9 + 7;

ll modpow(ll a, ll b) {
    ll ans = 1;

    while (b) {
        if (b & 1)
            ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }

    return ans;
}

int main() {
    fio();

    int a, b, n;
    cin >> a >> b >> n;
    cout << modpow(modpow(2, 31), n - 1);
}
