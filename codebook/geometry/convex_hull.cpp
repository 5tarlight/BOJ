using ll = long long;

struct Point {
    ll x, y;

    bool operator<(const Point &p) const {
        if (x == p.x) return y < p.y;
        return x < p.x;
    }
};

vector<Point> points;
vector<int> hull;
int n;

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

void convex() {
    sort(points.begin(), points.end());
    sort(points.begin() + 1, points.end(), cmp);

    hull.push_back(0);
    hull.push_back(1);

    for (int i = 2; i < n; i++) {
        while (hull.size() >= 2 && ccw(points[hull[hull.size() - 2]], points[hull[hull.size() - 1]], points[i]) <= 0)
            hull.pop_back();
        hull.push_back(i);
    }
}

//int main() {
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    ios_base::sync_with_stdio(false);
//
//    cin >> n;
//    points.resize(n);
//    for (int i = 0; i < n; i++)
//        cin >> points[i].x >> points[i].y;
//
//    convex();
//
//    cout << hull.size();
//}
