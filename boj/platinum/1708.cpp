#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Point {
    ll x, y;

    bool operator<(const Point &p) const {
        if (x == p.x) return y < p.y;
        return x < p.x;
    }
};

Point points[100000];

ll ccw(const Point &a, const Point &b, const Point &c) {
    ll res = a.x * b.y + b.x * c.y + c.x * a.y;
    res -= (a.y * b.x + b.y * c.x + c.y * a.x);

    return res;
}

ll dist(const Point &a, const Point &b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool cmp(const Point &a, const Point &b) {
    ll res = ccw(points[0], a, b);
    if (res == 0) return dist(points[0], a) < dist(points[0], b);
    return res > 0;
}

int hull[100000];
int idx = 0;

void add(int i) {
    hull[idx++] = i;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;
    sort(points, points + n);
    sort(points + 1, points + n, cmp);

    add(0);
    add(1);

    for (int i = 2; i < n; i++) {
        while (idx >= 2 && ccw(points[hull[idx - 2]], points[hull[idx - 1]], points[i]) <= 0)
            idx--;
        add(i);
    }

    cout << idx;
}
