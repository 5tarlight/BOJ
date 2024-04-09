#include <iostream>
#include <cmath>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    long long x, y, w, s;
    cin >> x >> y >> w >> s;

    long long ans = 0;
    long long gap =  abs(x - y);

    if (w > s) {
        if ((gap & 1) == 0)
            ans += gap * s;
        else {
            ans += (gap / 2) * 2 * s;
            ans += w;
        }
    } else {
        ans += gap * w;
    }

    if (x < y)
        y = x;
    else
        x = y;

    if (2 * w < s) {
        ans += (x + y) * w;
    } else {
        ans += x * s;
    }

    cout << ans;
}
