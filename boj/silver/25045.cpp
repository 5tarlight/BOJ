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
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int b[m];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(a, a + n, greater<>());
    sort(b, b + m);

    long long ans = 0;
    for (int i = 0; i < min(n, m); i++)
        ans += max(a[i] - b[i], 0);

    cout << ans;
}
