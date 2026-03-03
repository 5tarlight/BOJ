#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    int n; cin >> n;
    double a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int tmp = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            bool ok = true;
            for (int k = min(i, j) + 1; k <= max(i, j) - 1; k++) {
                int w = k - i;
                double h = a[i] + (a[j] - a[i]) * (double)(k - i) / (j - i);
                if (a[k] >= h) {
                    ok = false;
                    break;
                }
            }

            if (ok) tmp++;
        }

        ans = max(ans, tmp);
    }

    cout << ans;
}
