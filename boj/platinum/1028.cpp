#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int n, m;
bool a[750][750];
int ld[750][750], rd[750][750];

int get(int x, int y) {
    int l = min(ld[x][y], rd[x][y]);
    for (int i = l; l > 0; i--) {
        if (rd[x + i - 1][y - i + 1] >= i && ld[x + i - 1][y + i - 1] >= i) {
            return i;
        }
    }

    return 0;
}

int main() {
    fio();

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j] == '1';
        }
    }

    memset(ld, 0, sizeof(ld));
    memset(rd, 0, sizeof(rd));

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (a[i][j]) {
                ld[i][j] = 1;
                if (i + 1 < n && j - 1 >= 0)
                    ld[i][j] += ld[i + 1][j - 1];
            }
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (a[i][j]) {
                rd[i][j] = 1;
                if (i + 1 < n && j + 1 < m)
                    rd[i][j] += rd[i + 1][j + 1];
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j]) {
                ans = max(ans, get(i, j));
            }
        }
    }

    cout << ans;
}
