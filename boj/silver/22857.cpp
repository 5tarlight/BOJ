#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int ans = 0;
    int cnt = 0;

    int l = 0, r = 0;

    while (++r <= n) {
        if (a[r - 1] & 1)
            cnt++;

        while (cnt > k) {
            l++;
            if (a[l - 1] & 1)
                cnt--;
        }

        ans = max(ans, r - l - cnt);
    }

    cout << ans;
}
