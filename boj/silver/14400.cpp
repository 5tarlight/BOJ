#include "bits/stdc++.h"

using namespace std;

int dist (pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

struct Cmp1 {
    bool operator() (pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
    }
};

struct Cmp2 {
    bool operator() (pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    }
};

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    pair<int, int> a[n];
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[i] = { x, y };
    }

    sort(a, a + n, Cmp1());
    int x = a[n / 2].first;
    sort(a, a + n, Cmp2());
    int y = a[n / 2].second;

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += dist({ x, y }, a[i]);
    }

    cout << ans;
}
