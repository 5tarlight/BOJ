#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    double c;
    int n;
    cin >> c >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    int freeze = min((int)(c / 0.99), 2);
    int zero = 0;
    int maxLen = 0;
    int ans = 0;

    int l = 0;
    for (int r = 0; r < n; r++) {
        if (a[r] == 0) zero++;

        while (zero > freeze) {
            if (a[l++] == 0) zero--;
        }

        int len = r - l + 1;
        if (maxLen < len) {
            maxLen = len;
            ans = max(ans, *max_element(a + l, a + r + 1));
        } else if (maxLen == len) {
            ans = max(ans, *max_element(a + l, a + r + 1));
        }
    }

    cout << maxLen << '\n' << ans;
}
