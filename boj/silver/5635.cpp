#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    tuple<int, int, int, string> a[n];
    for (int i = 0; i < n; i++) {
        string name;
        int y, m, d;
        cin >> name >> d >> m >> y;

        a[i] = { y, m, d, name };
    }

    sort(a, a + n);

    string name;
    int x, y, z;
    tie(x, y, z, name) = a[n - 1];
    cout << name << '\n';
    tie(x, y, z, name) = a[0];
    cout << name;
}
