#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int p1, p2, p3, x1, x2, x3;
    cin >> p1 >> p2 >> p3 >> x1 >> x2 >> x3;

    int ans = -1;
    for (int n = 1; n <= p1 * p2 * p3; n++) {
        if (
                n % p1 == x1 &&
                n % p2 == x2 &&
                n % p3 == x3
        ) {
            ans = n;
            break;
        }
    }

    cout << ans;
}
