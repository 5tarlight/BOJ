#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> loc;
    int l = -1;
    int r = -1;

    long long dist = 0;
    while (n--) {
        int a, b;
        cin >> a >> b;
        if (a > b)
            loc.emplace_back(b, a);
    }

    sort(loc.begin(), loc.end());

    for (auto &p : loc) {
        if (r < p.first) {
            dist += r - l;
            l = p.first;
            r = p.second;
        } else {
            r = max(r, p.second);
        }
    }

    dist += r - l;
    cout << m + 2 * dist;
}
