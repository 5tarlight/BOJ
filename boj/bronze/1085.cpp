#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int x, y, w, h;
    cin >> x >> y >> w >> h;
    int dist = min(x, y);
    dist = min(dist, abs(w - x));
    dist = min(dist, abs(h - y));

    cout << dist;
}
