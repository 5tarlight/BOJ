#include <iostream>

using namespace std;


const long long MOD = 1000000007;
long long fac[4000001];

long long pow(long long a, long long n) {
    if (n == 0)
        return 1;
    else if (n == 1)
        return a % MOD;
    else if (n % 2 == 0) {
        long long d1 = pow(a, n / 2);
        return d1 * d1 % MOD;
    } else {
        long long d1 = pow(a, n / 2);
        return d1 * d1 % MOD * a % MOD;
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    fac[0] = 1;
    for (long long i = 1; i <= 4000000; i++)
        fac[i] = (i % MOD) * (fac[i - 1] % MOD) % MOD;

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        long long a = fac[k] * fac[n - k] % MOD;
        long long base = pow(a, MOD - 2);
        cout << fac[n] * base % MOD << '\n';
    }
}
