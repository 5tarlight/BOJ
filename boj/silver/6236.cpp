#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int a[n];
    int l = -1, r = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        l = max(l, a[i]);
        r += a[i];
    };

    while (l < r) {
        int mid = (l + r) / 2;
        int cnt = 1;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            if (sum + a[i] > mid) {
                cnt++;
                sum = a[i];
            } else {
                sum += a[i];
            }
        }

        if (cnt > m) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    cout << l;
}
