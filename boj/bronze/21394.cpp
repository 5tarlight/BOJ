#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int cnt[10];
        int all = 0;
        for (int i = 1; i <= 9; i++) {
            cin >> cnt[i];
            all += cnt[i];
        }
        cnt[9] += cnt[6];
        cnt[6] = 0;

        int idx = 9;
        int ans[all];
        for (int i = 0; i < all; i++) {
            while (cnt[idx] == 0)
                idx--;
            if (i % 2 == 0)
                ans[i / 2] = idx;
            else
                ans[all - i / 2 - 1] = idx;
            cnt[idx]--;
        }

        for (int v : ans)
            cout << v << ' ';
        cout << '\n';
    }
}
