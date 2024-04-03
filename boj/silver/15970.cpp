#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    pair<int, int> a[n];
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[i] = {y, x};
    }
    sort(a, a + n);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int d1 = 1e9;
        int d2 = 1e9;

        if (i > 0 && a[i].first == a[i - 1].first) {
            d1 = a[i].second - a[i - 1].second;
        }
        if (i < n - 1 && a[i].first == a[i + 1].first) {
            d2 = a[i + 1].second - a[i].second;
        }

        ans += min(d1, d2);
    }

    cout << ans;
}
