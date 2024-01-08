#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define X first
#define Y second

typedef long long ll;
typedef pair<ll, ll> p;

int ccw(p &a, p &b, p &c) {
    ll temp = a.X * b.Y + b.X * c.Y + c.X * a.Y;
    temp -= b.X * a.Y + c.X * b.Y+ a.X* c.Y;

    if (temp > 0)
        return 1;
    else if (temp == 0)
        return 0;
    else
        return -1;
}

bool isCross(p a, p b, p c, p d) {
    ll a1 = ccw(a, b, c) * ccw(a, b, d);
    ll a2 = ccw(c, d, a) * ccw(c, d, b);

    if (a1 == 0 && a2 == 0) {
        if (a > b)
            swap(a, b);
        if (c > d)
            swap(c, d);

        if (a <= d && b >= c)
            return true;
        else
            return false;
    } else {
        if (a1 <= 0 && a2 <= 0)
            return true;
        else
            return false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    vector<p> points;

    for (int i = 0; i < 4; i++) {
        int x, y;
        cin >> x >> y;
        points.emplace_back(x, y);
    }

    cout << (isCross(points[0], points[1], points[2], points[3]) ? 1 : 0);
}
