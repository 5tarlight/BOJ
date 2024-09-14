#include "bits/stdc++.h"

using namespace std;

bool np[1000001];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    np[0] = np[1] = true;
    vector<int> primes;
    for (int i = 2; i <= 1000000; i++) {
        if (!np[i]) {
            primes.push_back(i);
            for (int j = i + i; j <= 1000000; j += i)
                np[j] = true;
        }
    }

    int n;
    cin >> n;
    for (int p : primes) {
        if (p > n) break;

        int nxt = n - p;
        for (int pp : primes) {
            if (pp > nxt) break;

            int nnxt = nxt - pp;

            for (int ppp : primes) {
                if (ppp > nnxt) break;

                if (!np[nnxt - ppp]) {
                    cout << p << ' ' << pp << ' ' << ppp << ' ' << nnxt - ppp;
                    return 0;
                }
            }
        }
    }

    cout << -1;
}
