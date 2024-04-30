#include <iostream>
#include <map>
#include <string>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

int parseInt(string s) {
    int h = (s[0] - '0') * 10 + (s[1] - '0');
    int m = (s[3] - '0') * 10 + (s[4] - '0');
    return h * 60 + m;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int week = m / 7;
    map<string, pair<int, int>> mp[week]; // name: day, time
    set<string> names;

    while (n--) {
        string name, start, end;
        int day;
        cin >> name >> day >> start >> end;

        names.insert(name);
        int w = (day - 1) / 7;
        int minutes = parseInt(end) - parseInt(start);

        if (mp[w].find(name) == mp[w].end()) {
            mp[w][name] = {1, minutes};
        } else {
            mp[w][name].first++;
            mp[w][name].second += minutes;
        }
    }

    vector<string> ans;
    for (auto &name : names) {
        bool real = true;
        for (int i = 0; i < week; i++) {
            if (mp[i].find(name) == mp[i].end()) {
                real = false;
                break;
            }

            int days = mp[i][name].first;
            int minutes = mp[i][name].second;

            if (days < 5 || minutes < 60 * 60) {
                real = false;
                break;
            }
        }

        if (real)
            ans.push_back(name);
    }

    sort(ans.begin(), ans.end());

    if (ans.empty()) {
        cout << -1;
    } else {
        for (auto &name : ans)
            cout << name << '\n';
    }
}
