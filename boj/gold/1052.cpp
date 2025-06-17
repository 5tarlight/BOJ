#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    int n, k;
    cin >> n >> k;
    int cnt = __builtin_popcount(n);

    int ans = 0;
    int tmp = 1;
    while (cnt > k && tmp <= n) {
        if (n & tmp) {
            n += tmp;
            cnt = __builtin_popcount(n);
            ans += tmp;
        }
        tmp <<= 1;
    }

    if (cnt <= k) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
}
