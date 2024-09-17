#include "bits/stdc++.h"

using namespace std;

using cpx = complex<long double>;
using ll = long long;

void fft(vector<cpx> &a, bool inv = false) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        while (!((j ^= bit) & bit))
            bit >>= 1;
        if (i < j) swap(a[i], a[j]);
    }

    for (int i = 1; i < n; i <<= 1) {
        double x = inv ? M_PI / i : -M_PI / i;
        cpx w(cos(x), sin(x));

        for (int j = 0; j < n; j += i << 1) {
            cpx p(1, 0);

            for (int k = 0; k < i; k++) {
                cpx t = a[i + j + k] * p;
                a[i + j + k] = a[j + k] - t;
                a[j + k] += t;
                p *= w;
            }
        }
    }

    if (inv)
        for (int i = 0; i < n; i++)
            a[i] /= n;
}

vector<cpx> mul(vector<cpx>& a, vector<cpx>& b) {
    vector<cpx> pa(a.begin(), a.end());
    vector<cpx> pb(b.begin(), b.end());

    int n = 1;
    while (n < max(pb.size(), pa.size()))
        n <<= 1;
    n <<= 1;

    pa.resize(n);
    pb.resize(n);

    fft(pa);
    fft(pb);

    vector<cpx> ans(n);
    for (int i = 0; i < n; i++)
        ans[i] = pa[i] * pb[i];
    fft(ans, true);

    for (int i = 0; i < n; i++)
        ans[i] = cpx(round(ans[i].real()), 0);

    return ans;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> t(n), s(n);
    vector<cpx> q(n);

    for (int i = 1; i < n; i++) {
        t[1LL * i * i % n]++;
        s[2LL * i * i % n]++;
    }

    for (int i = 0; i < n; i++)
        q[i] = cpx(t[i], 0);

    auto m = mul(q, q);

    ll ans = 0;
    for (int i = 1; i < n; i++) {
        int k = 1LL * i * i % n;
        int a = m[k].real() + m[n + k].real();
        int e = s[k];

        ans += (a - e) / 2 + e;
    }

    cout << ans;
}
