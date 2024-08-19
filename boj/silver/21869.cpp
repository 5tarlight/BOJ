#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    if (n == 1) {
        cout << 1 << '\n' << "1 1";
        return 0;
    }

    cout << 2 * n - 2 << '\n';
    for (int i = 1; i <= n; i++)
        cout << 1 << ' ' << i << '\n';
    for (int i = 2; i < n; i++)
        cout << n << ' ' << i << '\n';
}
