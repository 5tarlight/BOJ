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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    while (m--) {
        int d;
        cin >> d;
        int idx = lower_bound(a, a + n, d) - a;

        if (idx < n && a[idx] == d) {
            cout << idx << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
}
