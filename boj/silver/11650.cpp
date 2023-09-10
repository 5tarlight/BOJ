#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> vec;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        vec.emplace_back(x, y);
    }

    sort(vec.begin(), vec.end());

    for (int i = 0; i < n; i++) {
        cout << vec[i].first << ' ' << vec[i].second << '\n';
    }
}
