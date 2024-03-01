#include <iostream>
#include <algorithm>

using namespace std;

int p[4000001];

int find(int x) {
    if (x == p[x])
        return x;
    else
        return p[x] = find(p[x]);
}

void uni(int x, int y) {
    int px = find(x);
    int py = find(y);

    if (px != py)
        p[x] = py;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;
    int a[m];
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        p[i] = i;
    }
    sort(a, a + m);

    while (k--) {
        int t;
        cin >> t;

        int idx = find(upper_bound(a, a + m, t) - a);
        cout << a[idx] << '\n';

        uni(idx, idx + 1);
    }
}
