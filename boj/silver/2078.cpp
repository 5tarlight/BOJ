#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int x = 0;
    int y = 0;
    while (true) {
        if (a == 1) {
            y += b - 1;
            break;
        } else if (b == 1) {
            x += a - 1;
            break;
        }

        if (a > b) {
            x += a / b;
            a %= b;
        } else {
            y += b / a;
            b %= a;
        }
    }

    cout << x << ' ' << y;
}
