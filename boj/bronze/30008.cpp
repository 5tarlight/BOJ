#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    while (k--) {
        int x;
        cin >> x;
        int p = x * 100 / n;

        if (p <= 4) cout << "1 ";
        else if (p <= 11) cout << "2 ";
        else if (p <= 23) cout << "3 ";
        else if (p <= 40) cout << "4 ";
        else if (p <= 60) cout << "5 ";
        else if (p <= 77) cout << "6 ";
        else if (p <= 89) cout << "7 ";
        else if (p <= 96) cout << "8 ";
        else cout << "9 ";
    }
}
