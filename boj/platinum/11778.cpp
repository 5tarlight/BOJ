#include "bits/stdc++.h"

using namespace std;

map<long long, long long> cache;

constexpr long long DIV = 1000000007LL;

long long fibo(long long n) {
    if (n == 0) return 0;
    else if (n == 1 || n == 2) return 1;

    if (cache.find(n) != cache.end())
        return cache[n];

    if (n % 2 == 0) {
        auto m = n / 2;
        auto t1 = fibo(m - 1);
        auto t2 = fibo(m);
        cache[n] = (2 * t1 + t2) * t2 % DIV;
    } else {
        auto m = (n + 1) / 2;
        auto t1 = fibo(m - 1);
        auto t2 = fibo(m);
        cache[n] = (t2 * t2 + t1 * t1) % DIV;
    }

    return cache[n];
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    long long a, b;
    cin >> a >> b;
    cout << fibo(gcd(a, b));
}
