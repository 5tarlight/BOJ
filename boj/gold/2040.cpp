#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

using ll = long long;

int main() {
    fio();

    int n; cin >> n;
    for (int _ = 0; _ < 3; _++) {
        vector<ll> a(n + 1), p(n + 1), f(n + 1), m(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            p[i] = p[i - 1] + a[i];
        }

        f[0] = m[0] = 0;
        for (int i = 1; i <= n; i++) {
            f[i] = -p[i] + m[i - 1];
            m[i] = max(m[i - 1], p[i] - f[i]);
        }

        if (f[n] > 0) cout << "A\n";
        else if (f[n] < 0) cout << "B\n";
        else cout << "D\n";
    }
}
