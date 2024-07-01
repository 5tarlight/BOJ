#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int d = 0;
    int p = 0;

    while (n--) {
        char c;
        cin >> c;
        if (c == 'P')
            p++;
        else
            d++;

        if (p == d + 2 || d == p + 2) {
            cout << d << ':' << p;
            return 0;
        }
    }

    cout << d << ':' << p;
}
