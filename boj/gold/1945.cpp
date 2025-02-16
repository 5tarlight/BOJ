#include "bits/stdc++.h"

using namespace std;

typedef pair<pair<int, int>, int> p;

struct Cmp {
    bool operator()(p &a, p &b) {
        double ga = (double)a.first.second / a.first.first;
        double gb = (double)b.first.second / b.first.first;

        if (ga == gb) return a.second > b.second;
        return ga > gb;
    }
};

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<p> points;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        points.push_back({ { x1, y2 }, 1 });
        points.push_back({{ x2, y1 }, -1 });
    }

    sort(points.begin(), points.end(), Cmp());

    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < points.size(); i++) {
        ans = max(ans, cnt);
        cnt += points[i].second;
    }

    cout << ans;
}
