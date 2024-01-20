#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int a[n];

    for (int i = 0; i < n; i++) {
        int p, l;
        cin >> p >> l;
        if (l > p) {
            a[i] = 0;
            int trash;
            while (p--)
                cin >> trash;
            continue;
        }

        int applies[p];
        for (int j = 0; j < p; j++)
            cin >> applies[j];
        sort(applies, applies + p, greater<>());
        a[i] = applies[l - 1];
    }

    sort(a, a + n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int v = a[i];
        if (m >= v && m > 0) {
            ans++;
            if (v == 0)
                m--;
            else
                m -= v;
        } else
            break;
    }

    cout << ans;
}
