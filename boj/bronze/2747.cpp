#include "bits/stdc++.h"

using namespace std;

unordered_map<long long, long long> cache;

long long fibo(long long n) {
    if (n == 0) return 0;
    else if (n == 1 || n == 2) return 1;

    if (cache.find(n) != cache.end())
        return cache[n];

    if (n % 2 == 0) {
        auto m = n / 2;
        auto t1 = fibo(m - 1);
        auto t2 = fibo(m);
        cache[n] = (2 * t1 + t2) * t2;
    } else {
        auto m = (n + 1) / 2;
        auto t1 = fibo(m - 1);
        auto t2 = fibo(m);
        cache[n] = (t2 * t2 + t1 * t1);
    }

    return cache[n];
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    cout << fibo(n);
}
