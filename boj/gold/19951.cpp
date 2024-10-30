#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int tmp[n + 1];
    fill(tmp, tmp + n + 1, 0);
    while (m--) {
        int l, r, k;
        cin >> l >> r >> k;
        tmp[l - 1] += k;
        tmp[r] -= k;
    }

    int sum[n];
    sum[0] = tmp[0];
    for (int i = 1; i < n; i++)
        sum[i] = tmp[i] + sum[i - 1];

    for (int i = 0; i < n; i++)
        cout << a[i] + sum[i] << ' ';
}
