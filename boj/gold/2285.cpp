#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    long long total = 0;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        total += y;
        a.push_back({ x, y });
    }

    sort(a.begin(), a.end());

    long long tmp = 0;
    for (auto [x, y] : a) {
        tmp += y;
        if (tmp * 2L >= total) {
            cout << x;
            return 0;
        }
    }
}
