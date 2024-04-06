#include <iostream>
#include <cmath>
#include <complex>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

const double PI = acos(-1);
typedef long long ll;
typedef complex<double> cpx;

void fft(vector<cpx> &v, bool inv) {
    ll n = v.size();

    for (ll i = 1, j = 0; i < n; i++) {
        ll bit = n / 2;

        while (j >= bit) {
            j -= bit;
            bit /= 2;
        }
        j += bit;

        if (i < j) {
            swap(v[i], v[j]);
        }
    }

    for (ll i = 1; i < n; i *= 2) {
        double theta = inv ? PI / i : -PI / i;
        cpx w(cos(theta), sin(theta));

        for (ll j = 0; j < n ; j += 2 * i) {
            cpx unit(1, 0);

            for (ll k = 0; k < i; k++) {
                cpx a = v[j + k];
                cpx b = v[j + k + i] * unit;

                v[j + k] = a + b;
                v[j + k + i] = a - b;

                unit *= w;
            }
        }
    }

    if (inv)
        for (int i = 0; i < n; i++)
            v[i] /= n;
}

vector<cpx> mul(vector<cpx> &v, vector<cpx> &u) {
    ll n = 2;

    while (n < v.size() + u.size())
        n *= 2;

    v.resize(n);
    fft(v, false);
    u.resize(n);
    fft(u, false);

    vector<cpx> w(n);
    for (int i = 0; i < n; i++) {
        w[i] = v[i] * u[i];
    }
    fft(w, true);

    return w;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string a, b;
    cin >> a >> b;

    vector<cpx> v, u;
    for (char i : a) {
        v.push_back(cpx(i - '0', 0));
    }
    for (char i : b) {
        u.push_back(cpx(i - '0', 0));
    }

    reverse(v.begin(), v.end());
    reverse(u.begin(), u.end());

    vector<cpx> w = mul(v, u);
    vector<int> ans(w.size());

    for (int i = 0; i < ans.size(); i++)
        ans[i] = round(w[i].real());

    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] < 10)
            continue;

        if (i < ans.size() - 1)
            ans[i + 1] += ans[i] / 10;
        else
            ans.push_back(ans[i] / 10);

        ans[i] %= 10;
    }

    reverse(ans.begin(), ans.end());

    int i = 0;
    while (ans[i] == 0)
        i++;

    if (i >= ans.size())
        cout << 0;
    else {
        for (; i < ans.size(); i++)
            cout << ans[i];
    }
}
