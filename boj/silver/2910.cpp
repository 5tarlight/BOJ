#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

map<int, int> order;
map<int, int> m;

int cmp(pair<int, int> &a, pair<int, int> &b) {
    if (a.second == b.second)
        return order[a.first] < order[b.first];
    return a.second > b.second;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, c;
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        m[num]++;
        if (order[num] == 0)
            order[num] = i + 1;
    }

    vector<pair<int, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);

    for (auto &p : v) {
        for (int i = 0; i < p.second; i++)
            cout << p.first << ' ';
    }
}
