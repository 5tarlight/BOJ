#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    int p, m, c; cin >> p >> m >> c;
    int x; cin >> x;
    int ans = 1e9;

    for (int i = 1; i <= p; i++)
        for (int j = 1; j <= m; j++)
            for (int k = 1; k <= c; k++)
                ans = min(ans, abs(x - (i + j) * (j + k)));

    cout << ans;
}
