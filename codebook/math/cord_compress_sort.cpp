#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    pair<int, int> a[n]; // { value, index }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = { x, i };
    }

    sort(a, a + n);

    int prev = 1e9 + 1;
    int cnt = -1;
    for (int i = 0; i < n; i++) {
        if (prev != a[i].first)
            cnt++;

        prev = a[i].first;
        a[i].first = cnt;
        swap(a[i].first, a[i].second);
    }

    sort(a, a + n); // { index, compressed_index }

    for (int i = 0; i < n; i++)
        cout << a[i].second << ' ';
}
