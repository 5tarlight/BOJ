#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    map<string, int> mp;

    while (n--) {
        string s;
        cin >> s;
        if (s.length() < m)
            continue;

        if (mp.find(s) == mp.end())
            mp[s] = 1;
        else
            mp[s] = mp[s] + 1;
    }

    vector<pair<int, pair<int, string>>> v;
    for (auto &p : mp) {
        v.push_back(make_pair(100000 - p.second, make_pair(10 - p.first.length(), p.first)));
    }

    sort(v.begin(), v.end());

    for (auto &s : v) {
        cout << s.second.second << '\n';
    }
}
