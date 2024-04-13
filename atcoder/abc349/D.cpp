#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    long long l, r;
    cin >> l >> r;

    vector<pair<long long, long long>> ans;
    while (l < r) {
        if (l % 2 == 1) {
            ans.push_back({ l, l + 1 });
            l++;
            continue;
        }

        long long bit = 1;
        while (l % (1L << bit) == 0 && l + (1L << bit) <= r) {
            bit++;
        }

        ans.push_back({ l, l + (1L << (bit - 1)) });
        l += (1L << (bit - 1));
    }

    cout << ans.size() << '\n';
    for (auto& p : ans) {
        cout << p.first << ' ' << p.second << '\n';
    }
}
