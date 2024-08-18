#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    bool sieve[300001];
    fill(sieve, sieve + 300001, true);
    vector<int> prime;
    for (int i = 2; i <= 300000; i++) {
        if (!sieve[i]) continue;
        if (i % 7 == 1 || i % 7 == 6) {
            prime.push_back(i);

            for (int j = 2; i * j <= 300000; j++)
                sieve[i * j] = false;
        }
    }

    while (true) {
        int n;
        cin >> n;
        if (n == 1) break;

        cout << n << ":";
        for (auto p : prime) {
            if (p > n) break;

            if (n % p == 0)
                cout << ' ' << p;
        }

        cout << '\n';
    }
}
