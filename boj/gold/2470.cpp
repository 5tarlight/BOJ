#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    long long a[n];
    long long mx = 3000000001;
    long long ans[2];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);

    int l = 0;
    int r = n - 1;
    while (l < r) {
        long long v = a[l] + a[r];

        if (abs(v) < mx) {
            mx = abs(v);
            ans[0] = a[l];
            ans[1] = a[r];
        }

        if (v < 0)
            l++;
        else
            r--;
    }

    cout << ans[0] << ' ' << ans[1];
}
