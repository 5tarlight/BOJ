#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int a1, a2;
    cin >> a1 >> a2;
    int c;
    cin >> c;
    int n0;
    cin >> n0;

    bool ok = true;
    for (int n = n0; n <= 100; n++) {
        if (a1 * n + a2 > c * n) {
            ok = false;
            break;
        }
    }

    if (ok)
        cout << 1;
    else
        cout << 0;
}
