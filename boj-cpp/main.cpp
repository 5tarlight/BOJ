#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    pair<double, pair<int, int>> a[n];

    for (int i = 0; i < n; i++) {
        int idx, c, h;
        cin >> idx >> c >> h;

        a[i] = { -(double)h / c, { c, idx }};
    }

    sort(a, a + n);

    for (int i = 0; i < k; i++)
        cout << a[i].second.second << '\n';
}
