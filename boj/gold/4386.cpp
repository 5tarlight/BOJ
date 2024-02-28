#include <iostream>
#include <cmath>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

int parents[1001];

int find(int x) {
    if (x == parents[x])
        return x;
    else
        return parents[x] = find(parents[x]);
}

void uni(int x, int y) {
    parents[find(x)] = find(y);
}

double getDist(pair<double, double> &a, pair<double, double> &b) {
    double dx = a.first - b.first;
    double dy = a.second - b.second;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    pair<double, double> loc[n];
    vector<tuple<double, int, int>> dist;
    for (int i = 0; i < n; i++) {
        double a, b;
        cin >> a >> b;
        loc[i] = make_pair(a, b);
        parents[i] = i;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            dist.emplace_back(getDist(loc[i], loc[j]), i, j);
        }


    sort(dist.begin(), dist.end());

    double ans = 0;
    int cnt = 0;
    for (auto &t : dist) {
        double d;
        int a, b;
        tie(d, a, b) = t;

        if (find(a) != find(b)) {
            ans += d;
            uni(a, b);
            cnt++;

            if (cnt == n - 1)
                break;
        }
    }

    cout << ans;
}
