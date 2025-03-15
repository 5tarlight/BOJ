#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int a[m];
    int l = 1, r = 1;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        r = max(r, a[i]);
    }

    int ans = 1e9;

    while (l <= r) {
        int mid = (l + r) / 2;

        long long cnt = 0;
        for (int i = 0; i < m; i++) {
            cnt += a[i] / mid;
            if (a[i] % mid) cnt++;
        }

        if (cnt <= n) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans;
}
