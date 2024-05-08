#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b) {
    auto [w1, h1] = a.second;
    auto [w2, h2] = b.second;
    long long pp1 = w1 * w1 + h1 * h1;
    long long pp2 = w2 * w2 + h2 * h2;

    if (pp1 == pp2) {
        return a.first < b.first;
    }
    return pp1 > pp2;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    pair<int, pair<int, int>> a[n];
    for (int i = 1; i <= n; i++) {
        int w, h;
        cin >> w >> h;
        a[i - 1] = { i,  { w, h } };
    }

    sort(a, a + n, cmp);

    for (auto v : a) {
        cout << v.first << '\n';
    }
}
