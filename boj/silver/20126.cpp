#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m, s;
    cin >> n >> m >> s;
    pair<int, int> a[n];
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[i] = { x, x + y };
    }
    sort(a, a + n);

    int ans = 0;
    if (a[0].first >= m) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < n - 1; i++) {
        if (a[i].second + m <= a[i + 1].first) {
            cout << a[i].second;
            return 0;
        }
    }

    if (a[n - 1].second + m <= s) {
        cout << a[n - 1].second;
        return 0;
    }

    cout << -1;
}
