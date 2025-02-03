#include "bits/stdc++.h"

using namespace std;

struct Line {
    int a, b, c;
};

bool does_cross(Line &p1, Line &p2) {
    return p1.a * p2.b != p1.b * p2.a;
}

pair<double, double> intersect(Line &p1, Line &p2) {
    int D = p1.a * p2.b - p2.a * p1.b;
    double x = (double)(-p1.c * p2.b + p2.c * p1.b) / D;
    double y = (double)(p1.a * (-p2.c) + p2.a * p1.c) / D;

    return {x, y};
}

double triangleArea(pair<double, double> p1, pair<double, double> p2, pair<double, double> p3) {
    double x1 = p1.first, y1 = p1.second;
    double x2 = p2.first, y2 = p2.second;
    double x3 = p3.first, y3 = p3.second;

    return 0.5 * abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    cout << fixed << setprecision(4);
    while (t--) {
        int a1, b1, c1, a2, b2, c2, a3, b3, c3;
        cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2 >> a3 >> b3 >> c3;
        Line p1 = {a1, b1, c1};
        Line p2 = {a2, b2, c2};
        Line p3 = {a3, b3, c3};

        if (!does_cross(p1, p2) || !does_cross(p1, p3) || !does_cross(p2, p3)) {
            cout << 0.0 << '\n';
            continue;
        }

        auto l1 = intersect(p1, p2);
        auto l2 = intersect(p1, p3);
        auto l3 = intersect(p2, p3);

        double area = triangleArea(l1, l2, l3);
        cout << area << '\n';
    }
}
