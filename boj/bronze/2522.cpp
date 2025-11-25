#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n - i; j++)
            cout << ' ';
        for (int j = 0; j < i; j++)
            cout << '*';
        cout << '\n';
    }

    for (int i = n - 1; i >= 1; i--) {
        for (int j = 0; j < n - i; j++)
            cout << ' ';
        for (int j = 0; j < i; j++)
            cout << '*';
        cout << '\n';
    }
}
