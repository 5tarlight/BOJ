#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    bool sieve[100001] = {false};
    vector<int> primes;
    for (int i = 2; i <= 100000; i++) {
        if (!sieve[i]) {
            primes.push_back(i);
            for (int j = i + i; j <= 100000; j += i) {
                sieve[j] = true;
            }
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        for (int i = 0; i < primes.size(); i++) {
            if (n == 1) {
                break;
            }

            int cnt = 0;
            while (n >= primes[i] && n % primes[i] == 0) {
                n /= primes[i];
                cnt++;
            }

            if (cnt > 0)
                cout << primes[i] << ' ' << cnt << '\n';
        }
    }
}
