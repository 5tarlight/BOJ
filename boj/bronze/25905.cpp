#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    double ans = 1e9;
    double a[10];
    for (int i = 0; i < 10; i++)
        cin >> a[i];
    sort(a, a + 10, greater<>());

    for (int i = 0; i < 9; i++)
        ans *= a[i] / double(i + 1);

    cout.precision(9);
    cout << fixed << ans;
}
