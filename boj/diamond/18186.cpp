#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll f[1000003];
ll n, b, c;
ll ans = 0;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> b >> c;
    for (int i = 1; i <= n; i++)
        cin >> f[i];

    if (b < c) {
        for (int i = 1; i <= n; i++)
            ans += f[i];
        cout << ans * b << '\n';
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        if (f[i + 1] > f[i + 2]) {
            ll cnt = min(f[i], f[i + 1] - f[i + 2]);
            ans += (b + c) * cnt;

            f[i] -= cnt;
            f[i + 1] -= cnt;

            cnt = min(f[i], min(f[i + 1], f[i + 2]));
            ans += (b + 2 * c) * cnt;

            f[i] -= cnt;
            f[i + 1] -= cnt;
            f[i + 2] -= cnt;
        } else {
            ll cnt = min(f[i], min(f[i + 1], f[i + 2]));
            ans += (b + 2 * c) * cnt;

            f[i] -= cnt;
            f[i + 1] -= cnt;
            f[i + 2] -= cnt;

            cnt = min(f[i], f[i + 1]);
            ans += (b + c) * cnt;

            f[i] -= cnt;
            f[i + 1] -= cnt;
        }

        ans += b * f[i];
        f[i] = 0;
    }

    cout << ans;
}
