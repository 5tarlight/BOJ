#include <iostream>
#include <map>

#define DIV 1000000007LL
typedef long long ll;

using namespace std;

map<ll, ll> cache;

ll fibo(ll n) {
    if (n == 0)
        return 0;
    else if (n == 1 || n == 2)
        return 1;

    if (cache.count(n) > 0)
        return cache[n];

    if (n % 2 == 0) {
        ll m = n / 2;
        ll f1 = fibo(m - 1);
        ll f2 = fibo(m);
        cache[n] = (2 * f1 + f2) * f2 % DIV;
    } else {
        ll m = (n + 1) / 2;
        ll f1 = fibo(m);
        ll f2 = fibo(m - 1);
        cache[n] = (f1 * f1 + f2 * f2) % DIV;
    }

    return cache[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n;
    cin >> n;
    if (n % 2 == 0) n--;
    n++;
    cout << fibo(n);
}
