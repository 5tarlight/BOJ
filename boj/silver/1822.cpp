#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    map<int, bool> mp;
    int n, m;
    cin >> n >> m;
    while (n--) {
        int x;
        cin >> x;
        mp[x] = true;
    }
    while (m--) {
        int x;
        cin >> x;
        mp[x] = false;
    }

    vector<int> ans;
    for (auto& [key, value] : mp) {
        if (value) {
            ans.push_back(key);
        }
    }

    cout << ans.size() << '\n';
    if (!ans.empty())
        for (auto& x : ans)
            cout << x << ' ';
}
