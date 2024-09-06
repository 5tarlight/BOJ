using ull = unsigned long long;

ull pow(ull x, ull y, ull mod) {
    x %= mod;
    ull ans = 1;
    while (y) {
        if (y & 1) ans = (ans * x) % mod;
        x = (x * x) % mod;
        y /= 2;
    }

    return ans;
}

bool partialPrime(ull n, ull a) {
    if (a % n == 0) return true;
    ull k = n - 1;

    while (true) {
        ull tmp = pow(a, k, n);

        if (tmp == n - 1) return true;
        if (k & 1) return tmp == 1 || tmp == n - 1;

        k /= 2;
    }
}

bool isPrime(ull n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    ull a[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };
    for (ull v : a)
        if (!partialPrime(n, v))
            return false;

    return true;
}