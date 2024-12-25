#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, s;
    cin >> n >> s;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);

    long long ans = 0;

    int l = 0, r = n - 1;
    while (l < r) {
        if (a[l] + a[r] > s)
            r--;
        else {
            ans += r - l;
            l++;
        }
    }

    cout << ans;
}
