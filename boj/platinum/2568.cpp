#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> a;
    vector<int> pos;
    vector<int> ans;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a.emplace_back(x, y);
    }

    sort(a.begin(), a.end());
    ans.push_back(a.front().second);
    pos.push_back(0);

    for (int i = 1; i < n; i++) {
        int nxt = a[i].second;

        if (ans.back() < nxt) {
            ans.push_back(nxt);
            pos.push_back(ans.size() - 1);
        } else {
            int idx = lower_bound(ans.begin(), ans.end(), nxt) - ans.begin();
            ans[idx] = nxt;
            pos.push_back(idx);
        }
    }

    cout << n - ans.size() << '\n';

    int target = ans.size() - 1;
    vector<int> removes;
    for (int i = n - 1; i >= 0; i--) {
        if (pos[i] == target)
            target--;
        else
            removes.push_back(a[i].first);
    }

    sort(removes.begin(), removes.end());
    for (int r : removes)
        cout << r << '\n';
}
