#include <iostream>
#include <cmath>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int x1, y1;
    cin >> x1 >> y1;
    int x2, y2;
    cin >> x2 >> y2;
    int dist = abs(x1 - x2) + abs(y1 - y2);
    int c;
    cin >> c;
    int gap = c - dist;

    if (gap % 2 == 0 && gap >= 0) {
        cout << 'Y';
    } else {
        cout << 'N';
    }
}
