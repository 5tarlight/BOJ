#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        cout << n / 25 << ' ';
        n %= 25;
        cout << n / 10 << ' ';
        n %= 10;
        cout << n / 5 << ' ';
        n %= 5;
        cout << n << '\n';
    }
}
