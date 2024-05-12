#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    bool m[501];
    fill(m, m + 501, false);
    pair<int, pair<int, int>> a[n];
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[i] = { i + 1, { x, y }};
    }
    int k;
    cin >> k;
    while (k--) {
        int num;
        cin >> num;
        m[num] = true;
    }

    int ans = 0;
    for (auto &p : a) {
        if (p.second.first == 0 || p.second.second == 0)
            continue;
        if (m[p.first] || m[p.second.first] || m[p.second.second])
            continue;
        ans++;
    }

    cout << ans;
}
