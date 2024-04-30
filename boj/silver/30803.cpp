#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int a[n];
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ans += a[i];
    }
    bool toggle[n];
    fill(toggle, toggle + n, true);
    int q;
    cin >> q;

    cout << ans << '\n';
    while (q--) {
        int op;
        cin >> op;

        if (op == 1) {
            int i, x;
            cin >> i >> x;
            int diff = x - a[i - 1];
            if (toggle[i - 1])
                ans += diff;
            a[i - 1] = x;
        } else {
            int i;
            cin >> i;
            i--;

            if (toggle[i]) {
                ans -= a[i];
            } else {
                ans += a[i];
            }

            toggle[i] = !toggle[i];
        }

        cout << ans << '\n';
    }
}
