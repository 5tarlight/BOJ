#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    int a[n]; // a[i] = 0 ^ i
    a[0] = 0;
    for (int i = 1; i < n; i++) {
        int num;
        cin >> num;
        a[i] = a[i - 1] ^ num;
    }

    while (q--) {
        int op;
        cin >> op;
        if (op == 0) {
            int x, y;
            cin >> x >> y;
            int x0 = a[x - 1];
            int y0 = a[y - 1];
            cout << (x0 ^ y0) << '\n';
        } else {
            int x, y, d;
            cin >> x >> y >> d;
            int xy = a[x - 1] ^ a[y - 1];
            cout << (xy ^ d) << '\n';
        }
    }
}
