#include "bits/stdc++.h"

using namespace std;

constexpr int MAX = 1500;
bool sieve[MAX + 1];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    fill(sieve, sieve + MAX + 1, true);
    sieve[0] = sieve[1] = false;
    for (int i = 2; i * i <= MAX; i++) {
        if (sieve[i]) {
            for (int j = 2 * i; j <= MAX; j += i)
                sieve[j] = false;
        }
    }

    int n;
    while (cin >> n) {
        if (n < 8) {
            cout << "Impossible.\n";
            continue;
        }

        if (n & 1) {
            cout << "2 3 ";
            n -= 5;
        } else {
            cout << "2 2 ";
            n -= 4;
        }

        for (int i = 2; i <= n; i++) {
            if (!sieve[i]) continue;
            if (sieve[n - i]) {
                cout << i << ' ' << n - i << '\n';
                break;
            }
        }
    }
}
