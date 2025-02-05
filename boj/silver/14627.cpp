#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    long long a[n];
    long long l = 1, r = -1;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        r = max(r, a[i]);
        sum += a[i];
    }

    long long ans = 0;
    while (l <= r) {
        long long tmp = 0;
        long long mid = (l + r + 1) / 2;
        for (int v : a) {
            tmp += v / mid;
        }

        if (tmp >= m) {
            ans = max(ans, mid);
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << sum - ans * m;
}
