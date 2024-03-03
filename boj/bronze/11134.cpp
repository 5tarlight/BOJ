#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        int n, c;
        cin >> n >> c;

        if (n % c == 0)
            cout << n / c << '\n';
        else
            cout << n / c + 1 << '\n';
    }
}
