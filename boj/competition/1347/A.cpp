#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int a[n + 1], b[n + 1];
    a[0] = b[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        a[i] += a[i - 1];
        b[i] += b[i - 1];

        cout << a[i] - b[i] << '\n';
    }
}

