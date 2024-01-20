#include <iostream>

using namespace std;

bool isIn(int x1, int y1, int x2, int y2, int r) {
    int d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);

    return r * r > d;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int n;
        cin >> n;

        int cnt = 0;
        while (n--) {
            int cx, cy, r;
            cin >> cx >> cy >> r;

            bool isIn1 = isIn(x1, y1, cx, cy, r);
            bool isIn2 = isIn(x2, y2, cx, cy, r);

            if (isIn1 && !isIn2 || !isIn1 && isIn2)
                cnt++;
        }

        cout << cnt << '\n';
    }
}
