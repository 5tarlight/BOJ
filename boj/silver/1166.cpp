#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n, l, w, h;
    cin >> n >> l >> w >> h;

    double s = 0;
    double r = 1'000'000'000;

    for (int i = 0; i < 10000; i++) {
        double m = (s + r) / 2.0;

        long long cnt = (long long)(l / m) * (long long)(w / m) * (long long)(h / m);
        if (cnt < n)
            r = m;
        else
            s = m;
    }

    printf("%.10lf", s);
}
