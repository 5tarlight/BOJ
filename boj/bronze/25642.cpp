#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;

    while (true) {
        b += a;
        if (b >= 5) {
            cout << "yt";
            break;
        }
        a += b;
        if (a >= 5) {
            cout << "yj";
            break;
        }
    }
}
