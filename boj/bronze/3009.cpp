#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int x1, x2, x3;
    int y1, y2, y3;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;

    int x, y;
    if (x1 == x2)
        x = x3;
    else if (x2 == x3)
        x = x1;
    else
        x = x2;

    if (y1 == y2)
        y = y3;
    else if (y2 == y3)
        y = y1;
    else
        y = y2;

    cout << x << ' ' << y;
}
