#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int a[n];
    int to = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        to = max(to, a[i]);
    }

    int ans = 0;
    for (int i = 1; i <= to; i <<= 1) {
        int cnt = 0;
        for (int j = 0; j < n; j++)
            if ((a[j] & i) != 0)
                cnt++;

        ans = max(ans, cnt);
    }

    cout << ans;
}
