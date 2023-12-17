#include <iostream>
#include <algorithm>

using namespace std;

int gcd(long long x, long long y) {
    return y ? gcd(y, x % y) : x;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    long long a, b;
    cin >> a >> b;

    cout << a * b / gcd(max(a, b), min(a, b)) << '\n';
}
