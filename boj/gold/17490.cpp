#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    long long k, cost = 0;
    cin >> n >> m >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<pair<int, int>> v;
    for (int _ = 0; _ < m; _++) {
        int i, j;
        cin >> i >> j;
        if (i > j && i != n) swap(i, j);

        v.push_back({ --i, --j });
    }

    if (m <= 1) {
        cout << "YES";
        return 0;
    }

    sort(v.begin(), v.end());

    int prev = 0;
    for (int i = 0; i < v.size(); i++) {
        int mn = INT_MAX;
        auto [l, r] = v[i];

        for (int j = prev; j <= l; j++)
            mn = min(mn, a[j]);
        if (prev == 0 && v.back().second != 0) {
            int e = v.back().second;
            for (int j = n - 1; j >= e; j--)
                mn = min(mn, a[j]);
        }
        cost += mn;
        prev = r;
    }

    if (cost <= k) cout << "YES";
    else cout << "NO";
}
