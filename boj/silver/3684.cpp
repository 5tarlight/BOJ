#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    int t; cin >> t;
    int a[t];
    for (int i = 0; i < t; i++) cin >> a[i];

    for (int x = 1; x <= 10000; x++) {
        for (int y = 1; y <= 10000; y++) {
            int prev = a[0];
            bool good = true;
            for (int i = 1; i < t; i++) {
                int tmp = (x * prev + y) % 10001;
                tmp = (x * tmp + y) % 10001;
                prev = tmp;
                if (a[i] != tmp) {
                    good = false;
                    break;
                }
            }

            if (good) {
                int ans = (x * a[0] + y) % 10001;
                for (int i = 0; i < t; i++) {
                    cout << ans << '\n';
                    ans = (x * ans + y) % 10001;
                    ans = (x * ans + y) % 10001;
                }
                return 0;
            }
        }
    }
}
