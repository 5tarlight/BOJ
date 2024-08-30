#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int l, t, n;
    cin >> l >> t >> n;
    vector<int> loc;

    while (n--) {
        int x;
        char d;
        cin >> x >> d;

        if (d == 'L') {
            int tmp = t - x;
            if (tmp < 0)
                x -= t;
            else {
                int a = tmp / l;
                int b = tmp % l;

                if (a % 2 == 1)
                    x = l - b;
                else
                    x = b;
            }
        } else {
            int tmp = t - (l - x);
            if (tmp < 0)
                x += t;
            else {
                int a = tmp / l;
                int b = tmp % l;
                if (a % 2 == 1)
                    x = b;
                else
                    x = l - b;
            }
        }

        loc.push_back(x);
    }

    sort(loc.begin(), loc.end());

    for (int v : loc)
        cout << v <<  ' ';
}