#include "bits/stdc++.h"

using namespace std;

#define MAX 1000000

using cpx = complex<double>;

void fft(vector<cpx> &data, bool inverse = false) {
    int size = data.size();
    for (int i = 1, j = 0; i < size; ++i) {
        int bit = size >> 1;
        while (!((j ^= bit) & bit)) bit >>= 1;
        if (i < j) swap(data[i], data[j]);
    }

    for (int len = 1; len < size; len <<= 1) {
        double angle = (inverse ? M_PI : -M_PI) / len;
        cpx w(cos(angle), sin(angle));
        for (int start = 0; start < size; start += len << 1) {
            cpx p(1, 0);
            for (int k = 0; k < len; ++k) {
                cpx tmp = data[start + len + k] * p;
                data[start + len + k] = data[start + k] - tmp;
                data[start + k] += tmp;
                p *= w;
            }
        }
    }

    if (inverse)
        for (int i = 0; i < size; ++i)
            data[i] /= size;
}

bool check[MAX + 1];
vector<int> primes;

void sieve() {
    for (int i = 2; i <= MAX; i++)
        if (!check[i])
            for (int j = i + i; j <= MAX; j += i)
                check[j] = true;

    for (int i = 3; i <= MAX; i++)
        if (!check[i])
            primes.push_back(i);
}

void mul(vector<cpx>& f, vector<cpx>& g, vector<cpx>& h) {
    fft(f);
    fft(g);

    for (int i = 0; i < f.size(); i++)
        h[i] = f[i] * g[i];

    fft(h, true);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    sieve();
    int t;
    cin >> t;
    vector<cpx> f(1 << 20), g(1 << 20), ans(1 << 20);

    for (int p : primes)
        f[(p - 1) / 2] = g[(p - 1) / 2] = cpx(1, 0);

    mul(f, g, ans);

    while (t--) {
        int n;
        cin >> n;
        if (n == 4)
            cout << "1\n";
        else
            cout << (int)ceil(round(ans[n / 2 - 1].real()) / 2) << '\n';
    }
}
