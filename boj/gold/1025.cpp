#include <bits/stdc++.h>
using namespace std;

void fio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    fio();

    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    long long ans = -1;

    for (int r0 = 0; r0 < n; r0++) {
        for (int c0 = 0; c0 < m; c0++) {
            // 한 자리 수 자체 확인
            long long single = a[r0][c0] - '0';
            long long s = sqrtl(single);
            if (s * s == single) ans = max(ans, single);

            for (int dr = -(n-1); dr <= n-1; dr++) {
                for (int dc = -(m-1); dc <= m-1; dc++) {
                    if (dr == 0 && dc == 0) continue;

                    long long val = 0;
                    int r = r0, c = c0;
                    while (r >= 0 && r < n && c >= 0 && c < m) {
                        val = val * 10 + (a[r][c] - '0');

                        long long s = sqrtl(val);
                        if (s * s == val)
                            ans = max(ans, val);

                        r += dr;
                        c += dc;
                    }
                }
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
