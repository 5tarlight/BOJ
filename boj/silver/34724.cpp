#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    int n, m; cin >> n >> m;

    string a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    bool found = false;
    for (int i = 0; i < n - 1 && !found; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (a[i][j] == '1' && a[i][j + 1] == '1' &&
                a[i + 1][j] == '1' && a[i + 1][j + 1] == '1') {
                found = true;
                break;
            }
        }
    }

    if (found) cout << 1;
    else cout << 0;
}
