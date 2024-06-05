#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    double x, y, c;
    cin >> x >> y >> c;

    double l = 1;
    double r = min(x, y);
    double ans = 0;

    while (l + 0.001 <= r) {
        double w = (l + r) / 2;
        double h1 = sqrt(x * x - w * w);
        double h2 = sqrt(y * y - w * w);
        double h = (h1 * h2) / (h1 + h2);

        if (h >= c) {
            ans = w;
            l = w;
        } else {
            r = w;
        }
    }

    cout << ans;
}
