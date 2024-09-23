#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    long long ans = 0;
    int a[n];

    int l = 0;
    map<int, int> cnt;
    for (int r = 0; r < n; r++) {
        int x;
        cin >> x;
        a[r] = x;
        cnt[x]++;

        while (cnt[x] > 1) {
            cnt[a[l++]]--;
        }

        ans += (r - l + 1);
    }

    cout << ans;
}

