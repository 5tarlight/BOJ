#include <iostream>

using namespace std;

int main() {
    double a, d, k;
    cin >> a >> d >> k;
    d /= 100.0;
    k /= 100.0;

    double ans = 0;
    double prev = 1;
    int i = 1;

    while (true) {
        ans += i * a * prev * d;
        i++;

        if (d == 1)
            break;

        prev *= 1 - d;
        d += d * k;

        if (d >= 1)
            d = 1;
    }

    cout.precision(7);
    cout << fixed << ans;
}
