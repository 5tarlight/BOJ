#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();
    bool sieve[10001];
    fill(sieve, sieve + 10001, true);
    sieve[0] = sieve[1] = false;
    vector<int> primes;
    for (int i = 2; i <= 10000; ++i) {
        if (sieve[i]) {
            primes.push_back(i);
            for (int j = i * 2; j <= 10000; j += i)
                sieve[j] = false;
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans = -1;
        for (int i = 0; i < primes.size(); ++i) {
            if (primes[i] > n / 2) break;
            if (sieve[n - primes[i]]) {
                ans = primes[i];
            }
        }

        cout << ans << ' ' << n - ans << '\n';
    }
}
