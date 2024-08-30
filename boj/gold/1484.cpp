#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int g;
    cin >> g;

    int l = 1, r = 1;

    bool found = false;
    while (!(r*r - l*l > g && r - l == 1)) {
        int cur = r*r - l*l;
        if (cur > g) l++;
        else if (cur < g) r++;
        else {
            found = true;
            cout << r << '\n';
            r++;
        }
    }

    if (!found)
        cout << -1;
}
