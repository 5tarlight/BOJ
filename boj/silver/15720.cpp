#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int b, c, d;
    cin >> b >> c >> d;
    int set = min({ b, c, d });
    int aa[b], bb[c], cc[d];

    int before = 0;
    for (int i = 0; i < b; i++) {
        cin >> aa[i];
        before += aa[i];
    }
    for (int i = 0; i < c; i++) {
        cin >> bb[i];
        before += bb[i];
    }
    for (int i = 0; i < d; i++) {
        cin >> cc[i];
        before += cc[i];
    }

    sort(aa, aa + b, greater<>());
    sort(bb, bb + c, greater<>());
    sort(cc, cc + d, greater<>());

    int dc = 0;
    for (int i = 0; i < set; i++) {
        int tmp = aa[i] + bb[i] + cc[i];
        dc += tmp / 10;
    }

    cout << before << '\n';
    cout << before - dc;
}
