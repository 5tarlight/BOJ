#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    struct Point { double x, y; };

    int n; cin >> n;
    vector<Point> fan;
    for (int i = 0; i < n; i++) {
        double x, y; cin >> x >> y;
        fan.push_back({x, y});
    }

    double w = 0.1;
    Point center = {0.0, 0.0};

    for (auto &f : fan) {
        center.x += f.x / n;
        center.y += f.y / n;
    }

    double mx;
    for (int i = 0; i < 1e6; i++) {
        mx = 0;
        Point tmp;
        for (auto &f : fan) {
            double d = sqrt((f.x - center.x) * (f.x - center.x) + (f.y - center.y) * (f.y - center.y));
            if (d > mx) {
                mx = d;
                tmp = f;
            }
        }

        center.x += (tmp.x - center.x) * w;
        center.y += (tmp.y - center.y) * w;
        w *= 0.9999;
    }

    cout << fixed << setprecision(10) << center.x << ' ' << center.y << ' ' << mx;
}
