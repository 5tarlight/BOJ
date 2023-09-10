#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int x1, y1, x2, y2, r1, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        double dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

        if (dist == 0 && r1 == r2)
            cout << -1 << '\n';
        else if (dist == r1 + r2 || dist == abs(r1 - r2))
            cout << 1 << '\n';
        else if (dist < r1 + r2 && dist > abs(r1 - r2))
            cout << 2 << '\n';
        else
            cout << 0 << '\n';
    }
}
