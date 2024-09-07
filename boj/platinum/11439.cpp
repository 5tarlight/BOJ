#include "bits/stdc++.h"

using namespace std;

using ll = long long;

bool prime[4000001];
vector<int> primes;
unordered_map<int, int> cnt;
int n, k, m;

ll comb(ll a, int b) {
    if (!b) return 1;
    if (b == 1) return a;
    if (b & 1) return comb(a, b - 1) * a % m;

    return comb(a * a % m, b / 2);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> k >> m;
    prime[1] = true;

    for (int i = 2; i <= n; i++) {
        if (prime[i]) continue;

        primes.push_back(i);
        for (int j = i * 2; j <= n; j += i)
            prime[j] = true;
    }

    for (int i = 0; i < primes.size(); i++)
        for (ll j = primes[i]; j <= n; j *= primes[i])
            cnt[primes[i]] += n / j - k / j - (n - k) / j;

    ll ans = 1;

    for (auto [i, j] : cnt) {
        ans *= comb(i, j);
        ans %= m;
    }

    cout << ans;
}
