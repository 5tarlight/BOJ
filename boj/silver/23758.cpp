#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    int ans = 1;
    int mid = (n + 1) / 2;
    for (int i = 0; i < mid; i++) {
        while (a[i] > 1) {
            a[i] /= 2;
            ans++;
        }
    }

    cout << ans;
}
