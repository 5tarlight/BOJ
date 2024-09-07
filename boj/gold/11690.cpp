#include "bits/stdc++.h"

using namespace std;

bool sieve[100000001];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    long long n;
    cin >> n;
    fill(sieve, sieve + n + 1, true);
    sieve[0] = sieve[1] = false;
    vector<int> primes;
    for (int i = 2; i * i <= n; i++) {
        if (sieve[i]) {
            for (int j = i * i; j <= n; j += i)
                sieve[j] = false;

        }
    }


    long long div = 1LL << 32;
    long long ans = 1;

    primes.push_back(2);
    for (int i = 3; i <= n; i += 2)
        if (sieve[i])
            primes.push_back(i);

    for (int i : primes) {
        long long p = i;
        while (p * i <= n)
            p = p * i % div;
        ans = ans * p % div;
    }

    cout << ans;
}