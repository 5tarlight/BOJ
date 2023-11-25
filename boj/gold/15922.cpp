#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    pair<int, int> lines[n];

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        lines[i] = make_pair(a, b);
    }

    sort(lines, lines + n);

    int ans = 0;
    int l = -1e9 - 1;
    int r = -1e9 - 1;
    for (auto &p : lines) {
        if (r < p.first) {
            ans += r - l;
            l = p.first;
            r = p.second;
        } else {
            r = max(r, p.second);
        }
    }
    ans += r - l;

    cout << ans;
}
