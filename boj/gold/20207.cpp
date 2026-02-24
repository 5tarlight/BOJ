#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    int n; cin >> n;
    pair<int, int> a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    int sum[366];
    memset(sum, 0, sizeof(sum));
    for (int i = 0; i < n; i++) {
        sum[a[i].first - 1]++;
        sum[a[i].second]--;
    }

    int ans = 0;
    int cur = 0;
    int w = 0;
    int tmp = 0;
    for (int i = 0; i < 365; i++) {
        cur += sum[i];
        if (cur > 0) {
            w++;
            tmp = max(tmp, cur);
        } else {
            ans += w * tmp;
            w = 0;
            tmp = 0;
        }
    }

    if (w > 0)
        ans += w * tmp;

    cout << ans;
}
