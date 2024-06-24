#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<pii> points;

ll dist(pii a, pii b) {
    int dx = a.first - b.first;
    int dy = a.second - b.second;
    return dx * dx + dy * dy;
}

ll solve(int l, int r) {
    if (r - l + 1 <= 3) {
        ll ans = 9e18;
        for (int i = l; i <= r; i++)
            for (int j = i + 1; j <= r; j++)
                ans = min(ans, dist(points[i], points[j]));
        return ans;
    }

    int mid = (l + r) / 2;
    ll left = solve(l, mid);
    ll right = solve(mid + 1, r);
    ll ans = min(left, right);

    vector<pii> center;
    for (int i = l; i <= r; i++) {
        int d = points[i].first - points[mid].first;
        if (d * d < ans)
            center.push_back(points[i]);
    }

    sort(center.begin(), center.end(), [&](const pii &a, const pii&b) {
        return a.second < b.second;
    });

    for (int i = 0; i < center.size(); i++) {
        for (int j = i + 1; j < center.size(); j++) {
            int y = center[i].second - center[j].second;

            if (y * y < ans)
                ans = min(ans, dist(center[i], center[j]));
            else
                break;
        }
    }

    return ans;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    points.resize(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        points[i] = {a, b};
    }

    sort(points.begin(), points.end());

    cout << solve(0, n - 1);
}
