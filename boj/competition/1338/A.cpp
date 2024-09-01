#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int q;
    cin >> q;
    int cur = 0;
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (a == 1)
            cur += b;
        else
            cur -= b;

        if (cur < 0) {
            cout << "Adios";
            return 0;
        }
    }

    cout << "See you next month";
}
