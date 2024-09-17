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

void mul(vector<cpx>& p) {
    int n = 1;
    while (n <= p.size()) n <<= 1;
    n <<= 1;

    p.resize(n);

    fft(p);
    for (int i = 0; i < n; i++)
        p[i] *= p[i];
    fft(p, true);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<cpx> v(200001);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v[x] = cpx(1, 0);
    }

    v[0] = cpx(1, 0);
    mul(v);

    int m;
    cin >> m;
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        if (round(v[x].real()) > 0)
            ans++;
    }

    cout << ans;
}
