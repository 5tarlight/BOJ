#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    if (n % 2 == 0) {
        for (int i = 0; i < n / 2; i++)
            cout << i + 1 << ' ' << -i - 1 << ' ';
        cout << 0;
    } else  {
        for (int i = 0; i < n / 2; i++)
            cout << i + 1 << ' ' << -i - 1 << ' ';
        cout << (n / 2 + 1) * n << ' ' << n / 2 + 1;
    }
}
