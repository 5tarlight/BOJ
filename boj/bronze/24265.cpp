#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    cout << n * (n - 1) / 2 << '\n';
    cout << 2;
}
