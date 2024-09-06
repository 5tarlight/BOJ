using ll = long long;
using ull = unsigned long long;

ll mult(ll p, ll q, ll mod){
    p %= mod;
    q %= mod;

    ull r = 0;
    ull w = p;

    while (q) {
        if (q & 1)
            r = (r + w) % mod;
        w = 2 * w % mod;
        q >>= 1;
    }

    return (ll)r;
}