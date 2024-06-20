#include <iostream>

using namespace std;

typedef unsigned long long ull;
int base[] = { 2, 7, 61 };

ull pow(ull x, ull y, ull mod) {
    ull ans = 1;
    x % mod;
    while (y) {
        if (y % 2 == 1) ans = (ans * x) % mod;
        y /= 2;
        x = (x * x) % mod;
    }

    return ans;
}

bool isPrime(ull n, ull a) {
    if (a % n == 0) return true;
    ull k = n - 1;

    while (true) {
        ull tmp = pow(a, k, n);

        if (tmp == n - 1) return true;
        if (k % 2 == 1) return tmp == 1 || tmp == n - 1;

        k /= 2;
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ull a;
        cin >> a;
        for (int j = 0; j < 3; j++) {
            if (!isPrime(2 * a + 1, base[j])) {
                ans++;
                break;
            }
        }
    }

    cout << n - ans;
}
