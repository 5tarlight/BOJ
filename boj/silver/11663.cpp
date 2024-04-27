#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int points[n];
    for (int i = 0; i < n; i++)
        cin >> points[i];
    pair<int, int> lines[m];
    for (int i = 0; i < m; i++)
        cin >> lines[i].first >> lines[i].second;

    sort(points, points + n);

    for (auto line : lines) {
        int l = line.first, r = line.second;
        int l_idx = lower_bound(points, points + n, l) - points;
        int r_idx = upper_bound(points, points + n, r) - points;
        cout << r_idx - l_idx << '\n';
    }
}
