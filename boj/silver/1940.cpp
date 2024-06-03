#include <iostream>
#include <algorithm>

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
    sort(a, a + n);
    int l = 0;
    int r = n - 1;
    int ans = 0;

    while (l < r) {
        if (a[l] + a[r] == m) {
            ans++;
            r--;
            l++;
        } else if (a[l] + a[r] < m) {
            l++;
        } else {
            r--;
        }
    }

    cout << ans;
}
