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
    int ans[3];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);

    for (int i = 0; i < n - 2; i++) {
        int l = i + 1;
        int r = n - 1;

        while (l < r) {
            long long v = a[i] + a[l] + a[r];

            if (abs(v) < mx) {
                mx = abs(v);
                ans[0] = a[i];
                ans[1] = a[l];
                ans[2] = a[r];
            }

            if (v < 0)
                l++;
            else
                r--;
        }
    }

    for (int i = 0; i < 3; i++)
        cout << ans[i] << ' ';
}
