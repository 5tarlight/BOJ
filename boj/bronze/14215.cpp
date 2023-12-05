#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;

    if (a == b && b == c && c == a) {
        cout << a * 3;
        return 0;
    }

    int m = max(a, max(b, c));

    if (m >= a + b + c - m)
        cout << (a + b + c - m) * 2 - 1;
    else
        cout << a + b + c;
}
