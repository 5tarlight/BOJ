#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    int n; cin >> n;
    int s[n], b[n];
    for (int i = 0; i < n; i++)
        cin >> s[i] >> b[i];

    int ans = 1e9;
    for (int i = 1; i < (1 << n); i++) {
        int ss = 1, bb = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                ss *= s[j];
                bb += b[j];
            }
        }

        ans = min(ans, abs(ss - bb));
    }

    cout << ans;
}
