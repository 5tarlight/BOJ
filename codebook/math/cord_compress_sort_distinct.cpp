#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    pair<int, int> a[n];
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = { x, i };
    }

    sort(a, a + n);

    for (int i = 0; i < n; i++) {
        a[i].first = i;
        swap(a[i].first, a[i].second);
    }

    sort(a, a + n);

    for (int i = 0; i < n; i++)
        cout << a[i].second << ' ';
}
