#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();


    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        a[i] = i + 1;

    int l = 0, r = n - 1;
    for (; l <= r; l++) {
        cout << a[l] << ' ';
        if (l != r)
            cout << a[r] << ' ';
        r--;
    }
}
