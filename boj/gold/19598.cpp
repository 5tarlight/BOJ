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
    vector<pair<int, int>> schedule(n);
    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        schedule[i] = make_pair(s, e);
    }

    sort(schedule.begin(), schedule.end());

    vector<pair<int, int>> labs;
    labs.emplace_back(0, 0);

    for (int i = 0; i < n; i++) {
        int s = schedule[i].first;
        int e = schedule[i].second;

        bool found = false;
        for (int j = 0; j < labs.size(); j++) {
            if (labs[j].second <= s) {
                found = true;
                labs[j].first = s;
                labs[j].second = e;
                break;
            }
        }

        if (!found) {
            labs.emplace_back(s, e);
        }
    }

    cout << labs.size();
}
