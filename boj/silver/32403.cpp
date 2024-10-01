#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, t;
    cin >> n >> t;
    int ans = 0;

    vector<int> subs;
    for (int i = 1; i <= t; i++)
        if (t % i == 0)
            subs.push_back(i);

    while (n--) {
        int x;
        cin >> x;

        int idx = lower_bound(subs.begin(), subs.end(), x) - subs.begin();

        if (idx == 0)
            ans += x - 1;
        else if (idx == subs.size()) {
            ans += x - subs.back();
        } else {
            ans += min(subs[idx] - x, x - subs[idx - 1]);
        }
    }

    cout << ans;
}
