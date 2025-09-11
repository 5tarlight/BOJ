#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    int n, k;
    cin >> n >> k;
    int sum[n + 1];
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        sum[i] = sum[i - 1] + x;
    }

    int ans = -1e9;
    for (int i = k; i <= n; i++) {
        ans = max(ans, sum[i] - sum[i - k]);
    }

    cout << ans;
}
