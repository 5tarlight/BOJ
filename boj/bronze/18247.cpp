#include "bits/stdc++.h"

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        if (r < 12 || c < 4) cout << "-1\n";
        else cout << c * 11 + 4 << '\n';
    }
}
