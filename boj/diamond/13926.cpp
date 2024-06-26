#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

typedef long long ll;
typedef __int128 lll;

namespace miller_rabin {
    ll mul(ll x, ll y, ll mod) {
        return (lll) x * y % mod;
    }

    ll binpow(ll x, ll y, ll mod) {
        ll res = 1;
        while (y > 0) {
            if (y & 1) {
                res = mul(res, x, mod);
            }
            x = mul(x, x, mod);
            y >>= 1;
        }
        return res;
    }

    bool miller_rabin(ll x, ll a) {
        if (x % a == 0)
            return false;

        ll d = x - 1;
        while (true) {
            ll temp = binpow(a, d, x);

            if (d & 1)
                return temp != 1 && temp != x - 1;
            else if (temp == x - 1)
                return false;

            d >>= 1;
        }
    }

    bool isPrime(ll x) {
        for (auto &a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
            if (x == a)
                return true;
            if (x > 40 && miller_rabin(x, a))
                return false;
        }

        if (x <= 40)
            return false;
        return true;
    }
}

namespace pollard_rho {
    ll gcd(ll a, ll b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

    void rho(ll n, vector<ll> &v) {
        if (n == 1)
            return;
        if ((n & 1) == 0) {
            v.push_back(2);
            rho(n / 2, v);
            return;
        }

        if (miller_rabin::isPrime(n)) {
            v.push_back(n);
            return;
        }

        ll a, b, c, g = n;
        auto logic = [&](ll x) {
            return (miller_rabin::mul(x, x, n) + c) % n;
        };

        do {
            if (g == n) {
                a = b = rand() % (n - 2) + 2;
                c = rand() % 20 + 1;
            }
            a = logic(a);
            b = logic(logic(b));
            g = gcd(abs(a - b), n);
        } while (g == 1);

        rho(g, v);
        rho(n / g, v);
    }

    vector<ll> factorize(ll n) {
        vector<ll> factors;
        rho(n, factors);
        sort(factors.begin(), factors.end());

        return factors;
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll n;
    cin >> n;
    ll cnt = 0;
    vector<ll> factors = pollard_rho::factorize(n);
    factors.erase(unique(factors.begin(), factors.end()), factors.end());

    for (int bit = 1; bit < (1 << factors.size()); bit++) {
        ll temp = 1;
        for (int i = 0; i < factors.size(); i++)
            if (bit & (1 << i))
                temp *= factors[i];
        cnt += (__builtin_popcount(bit) & 1) ? n / temp : -n / temp;
    }

    cout << n - cnt << '\n';
}
