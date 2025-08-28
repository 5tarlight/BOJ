#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    int n, k, m;
    cin >> n >> k >> m;

    vector<int> a;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x <= k) continue;
        else if (x < 2 * k) a.push_back(x - k);
        else a.push_back(x - 2 * k);
    }

    n = a.size();
    int l = 1, r = 1e9, ans = -1;

    while (l <= r) {
        int mid = (l + r) / 2;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += a[i] / mid;
        }

        if (cnt >= m) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans;
}
