#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    bool sieve[n + 1];
    vector<int> primes;
    fill(sieve, sieve + n + 1, true);
    sieve[0] = sieve[1] = false;
    for (int i = 2; i <= n; i++) {
        if (sieve[i]) {
            primes.push_back(i);
            for (int j = i * 2; j <= n; j += i) {
                sieve[j] = false;
            }
        }
    }

    int l = 0, r = 0, sum = 0, ans = 0;
    for (; l < primes.size(); l++) {
        while (r < primes.size() && sum < n) {
            sum += primes[r++];
        }
        if (sum == n) {
            ans++;
        }
        sum -= primes[l];
    }

    cout << ans;
}
