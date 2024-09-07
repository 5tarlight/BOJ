using ll = long long;

ll CCW(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
}