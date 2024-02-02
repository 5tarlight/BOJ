#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    long long m = 0;
    for (int i = 0; i < n - 1; i++) {
        m += a[i];
    }

    double ans = m / 2.0 + a[n - 1];
    cout << ans;
}
