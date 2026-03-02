#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> hex >> a[i];

    for (int i = 0; i < n; i++) {
        bool ok = false;
        for (int t = '0'; t <= '9'; t++) {
            int tmp = a[i] ^ t;
            if (tmp >= 'a' && tmp <= 'z') {
                ok = true;
                break;
            }
        }

        if (ok) cout << '-';
        else cout << '.';
    }
}
