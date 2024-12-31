#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int x, y;
    cin >> x >> y;
    int m;
    cin >> m;
    vector<int> v, h;
    v.push_back(0);
    h.push_back(0);
    while (m--) {
        int op, n;
        cin >> op >> n;
        if (op == 0)
            h.push_back(n);
        else
            v.push_back(n);
    }
    v.push_back(x);
    h.push_back(y);

    sort(h.begin(), h.end());
    sort(v.begin(), v.end());

    int ans = 0;
    for (int i = 1; i < h.size(); i++) {
        for (int j = 1; j < v.size(); j++) {
            ans = max(ans, (h[i] - h[i - 1]) * (v[j] - v[j - 1]));
        }
    }

    cout << ans;
}
