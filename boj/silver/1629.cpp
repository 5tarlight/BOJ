#include <iostream>

using namespace std;

long long int a, b, c;

long long int modular(long long int y) {
    if (y == 1)
        return a % c;

    long long int k = modular(y / 2) % c;

    if (y % 2 == 0)
        return k * k % c;
    else
        return k * k % c * a % c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> a >> b >> c;
    cout << modular(b);
}
