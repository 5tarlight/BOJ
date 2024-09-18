#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    cout.precision(9);
    while (t--) {
        double n1, m1, n2, m2;
        cin >> n1 >> m1 >> n2 >> m2;

        double temp = 1;
        for (int i = 0; i <= m1; i++)
            temp *= (n1 + 1 - i) / (n1 + n2 + 2 - i);

        double ans = temp;
        for (int i = 1; i <= m2; i++) {
            temp *= (m1 + i) / i * (n2 + 2 - i) / (n1 + n2 - m1 + 2 - i);
            ans += temp;
        }

        cout << fixed << ans << '\n';
    }
}
