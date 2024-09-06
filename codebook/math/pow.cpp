using ull = unsigned long long;

ull pow(ull x, ull e, ull mod) {
    ull ans = 1;
    x %= mod;

    while (e) {
        if (e & 1)
            ans = ans * x % mod;
        e >>= 1;
        x = x * x % mod;
    }

    return ans;
}