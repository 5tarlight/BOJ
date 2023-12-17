#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int x, int y) {
    return y ? gcd(y, x % y) : x;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int lcm = b * d / gcd(max(b, d), min(b, d));
    int head = a * (lcm / b) + c * (lcm / d);
    int div = gcd(max(head, lcm), min(head, lcm));
    cout << head / div << ' ' << lcm / div;
}
