typedef long long ll;

pair<ll, pair<ll, ll>> eea(ll a, ll b) {
    if (b == 0) return { a, {1, 0} };

    auto [g, xy] = eea(b, a % b);
    auto [x, y] = xy;
    return { g, { y, x - (a / b) * y  }};
}

ll mod_inv(ll a, ll mod) {
    auto res = eea(a, mod);
    if (res.first != 1) return -1;
    return (res.second.first % mod + mod) % mod;
}
