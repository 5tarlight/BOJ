#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

double ccw(double x1, double y1, double x2, double y2, double x3, double y3) {
    double res = (x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1);
    return res / 2;
}

int main() {
    int n;
    scanf("%d", &n);
    pair<double, double> p[n];
    for (int i = 0; i < n; i++)
        scanf("%lf %lf", &p[i].first, &p[i].second);

    double ans = 0;
    for (int i = 1; i < n; i++)
        ans += ccw(
                p[0].first, p[0].second,
                p[i - 1].first, p[i - 1].second,
                p[i].first, p[i].second
        );

    printf("%.1lf\n", abs(ans));
}
