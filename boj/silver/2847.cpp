#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;
    for (int i = n - 2; i >= 0; i--) {
        int tmp = max(a[i] - a[i + 1] + 1, 0);
        ans += tmp;
        a[i] -= tmp;
    }


    cout << ans;
}
