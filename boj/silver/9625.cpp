#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int a[n + 1];
    int b[n + 1];
    a[0] = 1;
    b[0] = 0;

    for (int i = 1; i <= n; i++) {
        b[i] = a[i - 1] + b[i - 1];
        a[i] = b[i - 1];
    }

    cout << a[n] << ' ' << b[n];
}
