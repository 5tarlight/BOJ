#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int cnt = n;
    for (int i = n - 1; i >= 0; i--)
        if (a[i] == cnt)
            cnt--;

    cout << cnt;
}
