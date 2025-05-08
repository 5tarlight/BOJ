#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    int n;
    cin >> n;
    double p[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    double ans = 0;
    for (int i = 0; i < n - 1; i++)
        ans += p[i] * (1 - p[i + 1]) + p[i + 1] * (1 - p[i]);
    for (int i = 0; i < n; i++)
        ans += p[i];

    cout << fixed << ans;
}
