#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    bool sieve[32769];
    fill(sieve, sieve + 32769, true);
    sieve[0] = sieve[1] = false;
    for (int i = 2; i <= 32768; i++) {
        if (sieve[i]) {
            for (int j = i * 2; j <= 32768; j += i) {
                sieve[j] = false;
            }
        }
    }

    while (true) {
        int n;
        cin >> n;
        if (n == 0)
            break;

        int count = 0;
        for (int i = 2; i <= n / 2; i++) {
            if (sieve[i] && sieve[n - i]) {
                count++;
            }
        }

        cout << count << '\n';
    }
}
