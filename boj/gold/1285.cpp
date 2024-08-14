#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    char a[n][n + 1];
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = 1e9;
    for (int bit = 0; bit < (1 << n); bit++) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int col = 0;
            for (int j = 0; j < n; j++) {
                if (bit & (1 << j)) {
                    if (a[j][i] == 'H')
                        col++;
                } else if (a[j][i] == 'T')
                    col++;
            }

            if (col > n / 2)
                col = n - col;
            cnt += col;
        }

        if (cnt < ans)
            ans = cnt;
    }

    cout << ans;
}
