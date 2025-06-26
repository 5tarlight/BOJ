#include <bits/stdc++.h>
using namespace std;

void fio() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
}

int main() {

    const int MAXK = 100000;
    vector<bool> sieve(MAXK + 1, true);
    sieve[0] = sieve[1] = false;

    for (int i = 2; i*i <= MAXK; i++)
        if (sieve[i])
            for (int j = i*i; j <= MAXK; j += i)
                sieve[j] = false;

    vector<int> primes;
    for (int i = 2; i <= MAXK; i++)
        if (sieve[i]) primes.push_back(i);

    int t;
    cin >> t;
    while (t--) {
        long long K;
        cin >> K;
        long long ans = LLONG_MAX;

        for (int i = 0; i < (int)primes.size(); i++) {
            long long p = primes[i];
            if (p * p >= ans) break;
            long long need = (K + p - 1) / p;
            auto it = lower_bound(primes.begin()+i+1, primes.end(), need);
            if (it != primes.end())
                ans = min(ans, p * (long long)*it);
        }
        cout << ans << "\n";
    }
}
