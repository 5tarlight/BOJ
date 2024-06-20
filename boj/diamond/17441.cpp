#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

struct Point {
    double x;
    double y;
};
vector<Point> p;

double cross(Point &a, Point &b, Point &c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
}

int main() {
    int n;
    cin >> n;
    p.resize(n);

    double area = 0;
    double v1 = 0;
    double v2 = 0;
    double v3 = 0;

    for (int i = 0; i < n; i++)
        cin >> p[i].x >> p[i].y;
    for (int i = 0; i < n - 1; i++)
        area += cross(p[0], p[i], p[i + 1]) / 2;

    for (int i = 0; i < n; i++) {
        double x = p[i].x;
        double xi = p[(i + 1) % n].x;
        double y = p[i].y;
        double yi = p[(i + 1) % n].y;

        v1 += (
                (yi - y) * (x * x * x + x * x * xi + x * xi * xi + xi*xi*xi)
                - (xi - x)
                * (y * y * y + y * y * yi + y * yi * yi + yi * yi * yi)
        ) / 12;
        v2 += (yi - y) * (x * x + x * xi + xi * xi) / 6;
        v3 += (xi - x) * (y * y + y * yi + yi * yi) / 6;
    }

    double ans = 2 / (area * area) * (area * v1 - v2 * v2 - v3 * v3);

    printf("%.10lf", ans);
}
