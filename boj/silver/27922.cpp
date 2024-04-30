#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    int a[n], b[n], c[n];

    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        a[i] = x + y;
        b[i] = x + z;
        c[i] = y + z;
    }

    sort(a, a + n, greater<>());
    sort(b, b + n, greater<>());
    sort(c, c + n, greater<>());

    int ans = 0;
    int asum = 0, bsum = 0, csum = 0;
    for (int i = 0; i < k; i++) {
        asum += a[i];
        bsum += b[i];
        csum += c[i];
    }
    ans = max(asum, max(bsum, csum));

    cout << ans;
}
