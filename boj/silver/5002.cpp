#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int x;
    string s;
    cin >> x >> s;
    deque<char> d;
    for (char c : s)
        d.push_back(c);

    int m = 0, w = 0;

    while (!d.empty()) {
        char f = d.front();
        d.pop_front();

        bool ok = false;
        if (f == 'M') {
            if (abs(m + 1 - w) <= x) {
                ok = true;
                m++;
            }
        } else {
            if (abs(w + 1 - m) <= x) {
                ok = true;
                w++;
            }
        }

        if (ok) continue;

        if (d.empty()) {
            cout << m + w;
            return 0;
        }

        char ff = d.front();
        d.pop_front();

        if (ff == 'M') {
            if (abs(m + 1 - w) <= x) {
                ok = true;
                m++;
            }
        } else {
            if (abs(w + 1 - m) <= x) {
                ok = true;
                w++;
            }
        }

        if (ok) {
            d.push_front(f);
        } else {
            cout << m + w;
            return 0;
        }
    }

    cout << m + w;
}
