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
        int a[n], b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int j = 0; j < m; j++)
            cin >> b[j];

        sort(b, b + m);

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int cnt = lower_bound(b, b + m, a[i]) - b;
            ans += cnt;
        }

        cout << ans << '\n';
    }
}
