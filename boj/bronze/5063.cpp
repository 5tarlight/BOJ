#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int r, e, c;
        cin >> r >> e >> c;

        if (e - c > r)
            cout << "advertise\n";
        else if (e - c == r)
            cout << "does not matter\n";
        else
            cout << "do not advertise\n";
    }
}
