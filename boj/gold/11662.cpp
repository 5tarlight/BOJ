#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

double ax, ay, bx, by, cx, cy, dx, dy;

double dist(double t) {
    double mx = ax + (bx - ax) * t;
    double my = ay + (by - ay) * t;

    double kx = cx + (dx - cx) * t;
    double ky = cy + (dy - cy) * t;

    return sqrt(pow(mx - kx, 2) + pow(my - ky, 2));
}

int main() {
    fio();

    cin >> ax >> ay >> bx >> by;
    cin >> cx >> cy >> dx >> dy;

    double l = 0, h = 1;

    for (int i = 0; i < 100; i++) {
        double p1 = l + (h - l) / 3;
        double p2 = h - (h - l) / 3;

        if (dist(p1) >= dist(p2)) l = p1;
        else h = p2;
    }

    cout << fixed << setprecision(10) << dist(l) << "\n";
}
