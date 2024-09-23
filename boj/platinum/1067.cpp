#include "bits/stdc++.h"

using namespace std;

using cpx = complex<long double>;
using ll = long long;

void fft(vector<cpx> &data, bool inverse=false) {
    int size = data.size();
    vector<cpx> roots(size / 2);

    // Bit reversal permutation
    for (int i = 1, j = 0; i < size; i++) {
        int bit = size / 2;

        while (j >= bit)
            j -= bit, bit >>= 1;

        if (i < (j += bit))
            swap(data[i], data[j]);
    }

    // Precompute roots of unity
    long double angle = 2 * acosl(-1) / size * (inverse ? -1 : 1);

    for (int i = 0; i < size / 2; i++)
        roots[i] = cpx(cosl(angle * i), sinl(angle * i));

    // FFT
    for (int len = 2; len <= size; len <<= 1) {
        int step = size / len;
        for (int start = 0; start < size; start += len) {
            for (int k = 0; k < len / 2; k++) {
                auto even = data[start + k];
                auto odd = data[start + k + len / 2] * roots[step * k];
                data[start + k] = even + odd;
                data[start + k + len / 2] = even - odd;
            }
        }
    }

    // Normalize if inverse FFT
    if (inverse) {
        for (auto &value : data)
            value /= size;
    }
}

vector<ll> multiply(vector<ll> &a, vector<ll> &b) {
    vector<cpx> fa(a.begin(), a.end());
    vector<cpx> fb(b.begin(), b.end());

    int n = 2;
    while (n < a.size() + b.size()) n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa);
    fft(fb);

    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<ll> ans(n);
    for (int i = 0; i < n; i++)
        ans[i] = (ll)round(fa[i].real());

    return ans;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<ll> a(2 * n);
    vector<ll> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[n - i];
    }

    vector<ll> ans = multiply(a, b);

    ll aa = 0;
    for (ll x : ans) {
        aa = max(x, aa);
    }

    cout << aa;
}
