#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int a[n];
    int temp[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        temp[i] = a[i];
    }
    int cnt[11];
    fill(cnt, cnt + 11, 0);

    int l = 0;
    int r = 0;
    int ans = 1;
    int mini = a[0];
    int maxi = a[0];
    cnt[a[r]]++;

    while (++r < n) {
        cnt[a[r]]++;

        if (a[r] > maxi)
            maxi = a[r];
        if (a[r] < mini)
            mini = a[r];

        if (maxi - mini > 2) {
            for (; ++l <= r;) {
                int prev = a[l - 1];
                cnt[prev]--;

                if (prev == mini && cnt[prev] == 0) {
                    mini = *min_element(a + l, a + r + 1);
                }
                if (prev == maxi && cnt[prev] == 0) {
                    maxi = *max_element(a + l, a + r + 1);
                }

                if (maxi - mini <= 2)
                    break;
            }

            if (l > r)
                l--;
        }

        ans = max(ans, r - l + 1);
    }

    cout << ans;
}
