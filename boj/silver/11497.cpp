#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());

        int ans = 0;
        for (int i = 2; i < n; i++)
            ans = max(ans, abs(a[i] - a[i - 2]));
        cout << ans << endl;
    }
}
