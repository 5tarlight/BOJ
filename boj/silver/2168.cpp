#include <iostream>

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int x, y;
    cin >> x >> y;
    int g = gcd(x, y);

    if (g == 1)
        cout << x + y - 1;
    else
        cout << x + y - g;
}
