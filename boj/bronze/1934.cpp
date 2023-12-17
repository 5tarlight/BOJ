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

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        cout << a * b / gcd(max(a, b), min(a, b)) << '\n';
    }
}
