#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    vector<int> a(8);
    int idx[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
    for (int i = 0; i < 8; i++)
        cin >> a[i];

    int ans = 0;

    do {
        bool ok = true;
        for (int i = 0; i < 8; i++) {
            int prev = i == 0 ? 7 : i - 1;
            int nxt = i == 7 ? 0 : i + 1;
            int p = a[idx[prev]];
            int n = a[idx[nxt]];
            int cur = a[idx[i]];

            if (cur < (double)p * n / (double)(p + n) * sqrt(2)) {
                ok = false;
                break;
            }
        }

        if (ok) ans++;
    } while (next_permutation(idx, idx + 8));

    cout << ans;
}
