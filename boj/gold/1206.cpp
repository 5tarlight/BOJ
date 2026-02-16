#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        float x; cin >> x;
        a[i] = (int)(x * 1000 + 0.5);
    }

    for (int p = 1; p <= 1000; p++) {
        bool ok = true;
        for (int i = 0; i < n; i++) {
            long long t1 = (1LL * p * a[i] + 999) / 1000;
            long long t2 = (1LL * p * a[i] + p - 1) / 1000;
            if (t1 > t2) {
                ok = false;
                break;
            }
        }

        if (ok) {
            cout << p;
            return 0;
        }
    }
}
