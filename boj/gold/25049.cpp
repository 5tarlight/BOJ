#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    ll a[n];
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ans += a[i];
    }

    ll lsum[n];
    ll ls[n];
    ls[0] = lsum[0] = a[0];
    for (int i = 1; i < n; i++) {
        lsum[i] = max(lsum[i - 1] + a[i], a[i]);
        ls[i] = max(ls[i - 1], lsum[i]);
    }

    ll rsum[n];
    ll rs[n];
    rs[n - 1] = rsum[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        rsum[i] = max(rsum[i + 1] + a[i], a[i]);
        rs[i] = max(rs[i + 1], rsum[i]);
    }

    ll m = max(0LL, ls[n - 1]);
    for (int i = 0; i < n - 1; i++)
        m = max(m, ls[i] + rs[i + 1]);

    cout << ans + m;
}
