#include <iostream>
#include <cmath>

using namespace std;

constexpr double e = 2.7182818459045;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int s, p;
    cin >> s >> p;
    if (s == p) {
        cout << 1;
        return 0;
    }

    if (pow(e, s / e) < p) {
        cout << -1;
        return 0;
    }

    double prev = -1;
    for (int i = 2;; i++) {
        double cur = pow(1.0 * s / i, i);
        if (prev > cur) {
            cout << -1;
            return 0;
        } else if (cur >= p) {
            cout << i;
            return 0;
        }

        prev = cur;
    }
}
