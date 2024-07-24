#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int x, y, p1, p2;
    cin >> x >> y >> p1 >> p2;
    int lcm = x * y / gcd(x, y);

    for (int i = 1; max(x, y) * i <= lcm; i++) {
        if (x * i + p1 == y * i + p2) {
            cout << x * i + p1;
            return 0;
        }
    }

    cout << -1;
}
