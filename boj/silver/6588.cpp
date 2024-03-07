#include <iostream>
#include <vector>

using namespace std;

bool isNotPrime[1000001];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    vector<int> primes;
    isNotPrime[1] = true;
    for (int i = 2; i <= 1000000; i++) {
        if (isNotPrime[i]) {
            continue;
        }
        primes.push_back(i);
        for (int j = i * 2; j <= 1000000; j += i) {
            isNotPrime[j] = true;
        }
    }

    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }

        for (int p : primes) {
            if (!isNotPrime[n - p]) {
                cout << n << " = " << p << " + " << n - p << '\n';
                break;
            }

        }
    }
}
