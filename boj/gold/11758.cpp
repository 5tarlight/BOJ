#include <iostream>

using namespace std;

typedef long long ll;

struct Point {
    ll x, y;
};

Point points[3];

int ccw(Point a, Point b, Point c) {
    ll res = a.x * b.y + b.x * c.y + c.x * a.y;
    res -= (a.y * b.x + b.y * c.x + c.y * a.x);
    if (res > 0) return 1;
    if (res < 0) return -1;
    return 0;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    for (int i = 0; i < 3; i++) {
        cin >> points[i].x >> points[i].y;
    }

    cout << ccw(points[0], points[1], points[2]);
}
