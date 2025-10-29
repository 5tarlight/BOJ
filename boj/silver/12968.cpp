#include <bits/stdc++.h>

using namespace std;

int main() {
    int r, c, k; cin >> r >> c >> k;

    if (k == 1) cout << 1;
    else if (r % 2 == 0 || c % 2 == 0) cout << 1;
    else cout << 0;
}
