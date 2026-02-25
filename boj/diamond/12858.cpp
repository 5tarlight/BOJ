#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

ll gcd(ll a, ll b) {
    while (b) {
        ll t = a % b;
        a = b; b = t;
    }
    return a;
}

ll g(ll a, ll b) {
    if (!a) return b;
    if (!b) return a;
    return gcd(a, b);
}

struct Lazy {
    ll t[404040], lz[404040];

    void push(int n, int s, int e) {
        if (!lz[n]) return;
        t[n] += (e - s + 1) * lz[n];
        if (s != e) {
            lz[n << 1] += lz[n];
            lz[n << 1 | 1] += lz[n];
        }
        lz[n] = 0;
    }

    void upd(int n, int s, int e, int l, int r, ll v) {
        push(n, s, e);
        if (r < s || e < l) return;
        if (l <= s && e <= r) {
            t[n] += (e - s + 1) * v;
            if (s != e) {
                lz[n << 1] += v;
                lz[n << 1 | 1] += v;
            }
            return;
        }
        int m = (s + e) >> 1;
        upd(n << 1, s, m, l, r, v);
        upd(n << 1 | 1, m + 1, e, l, r, v);
        t[n] = t[n << 1] + t[n << 1 | 1];
    }

    ll qry(int n, int s, int e, int x) {
        push(n, s, e);
        if (x < s || e < x) return 0;
        if (s == e) return t[n];
        int m = (s + e) >> 1;
        return qry(n << 1, s, m, x) + qry(n << 1 | 1, m + 1, e, x);
    }

    void upd(int l, int r, ll v) { upd(1, 1, 100000, l, r, v); }
    ll qry(int x) { return qry(1, 1, 100000, x); }
};

struct Seg {
    int t[404040];
    int b;

    Seg() { for (b = 1; b < 101010; b <<= 1); }

    void upd(int x, int v) {
        if (x <= 0) return;
        t[x += b] = v;
        while (x >>= 1) t[x] = g(t[x << 1], t[x << 1 | 1]);
    }

    ll qry(int l, int r) {
        if (l > r) return 0;
        l += b; r += b;
        int ret = 0;
        while (l < r) {
            if (l & 1) ret = g(ret, t[l++]);
            if (!(r & 1)) ret = g(ret, t[r--]);
            l >>= 1; r >>= 1;
        }
        if (l == r) ret = g(ret, t[l]);
        return ret;
    }
};

int main() {
    fio();

    int n; cin >> n;

    Lazy bit;
    Seg seg;

    for (int i = 1; i <= n; i++) {
        ll x; cin >> x;
        bit.upd(i, i, x);
    }

    for (int i = 1; i < n; i++) {
        ll d = bit.qry(i) - bit.qry(i + 1);
        seg.upd(i, abs(d));
    }

    int m; cin >> m;
    while (m--) {
        int op, a, b; cin >> op >> a >> b;
        if (!op) {
            ll v = seg.qry(a, b - 1);
            v = g(v, bit.qry(a));
            cout << v << '\n';
        } else {
            bit.upd(a, b, op);
            ll d1 = bit.qry(a - 1) - bit.qry(a);
            ll d2 = bit.qry(b) - bit.qry(b + 1);
            seg.upd(a - 1, abs(d1));
            seg.upd(b, abs(d2));
        }
    }
}