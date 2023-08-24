#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> vec;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        vec.emplace_back(y, x);
    }

    sort(vec.begin(), vec.end());

    for (int i = 0; i < n; i++) {
        cout << vec[i].second << ' ' << vec[i].first << '\n';
    }
}
