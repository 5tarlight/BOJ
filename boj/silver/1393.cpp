#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int sx, sy;
    int x, y, dx, dy;
    cin >> sx >> sy >> x >> y >> dx >> dy;

    double ans = 1e9;
    int ax, ay;

    int g = gcd(dx, dy);
    dx /= g;
    dy /= g;

    while (true) {
        int gx = sx - x;
        int gy = sy - y;
        double tmp = sqrt(gx * gx + gy * gy);

        if (tmp < ans) {
            ans = tmp;
            ax = x;
            ay = y;
        } else if (tmp > ans) break;

        x += dx;
        y += dy;
    }

    cout << ax << ' ' << ay;
}
