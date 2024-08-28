#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    long long n, m, k, x, y;
    cin >> n >> m >> k >> x >> y;
    auto ans = k * (x + y);
    long long a[n];
    for (int i = 0; i < n; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        a[i] = x * n1 - y * n2;
    }
    sort(a, a + n);
    for (int i = 0; i < m; i++)
        ans += a[i];
    cout << ans;
}
