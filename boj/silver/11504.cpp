#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int x = 0;
        int y = 0;
        for (int i = 0; i < m; i++) {
            int xx;
            cin >> xx;
            x = 10 * x + xx;
        }
        for (int i = 0; i < m; i++) {
            int yy;
            cin >> yy;
            y = 10 * y + yy;
        }

        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int tmp = 0;
            for (int j = 0; j < m; j++) {
                int idx = (i + j) % n;
                tmp = 10 * tmp + a[idx];
            }

            if (tmp >= x && tmp <= y) ans++;
        }

        cout << ans << '\n';
    }
}
