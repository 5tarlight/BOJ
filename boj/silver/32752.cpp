#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    int n, l, r;
    cin >> n >> l >> r;
    l--;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a + l, a + r);

    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            cout << 0;
            return 0;
        }
    }

    cout << 1;
}
