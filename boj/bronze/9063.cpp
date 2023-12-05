#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n;
    int xl = 123456;
    int yl = 123456;
    int xr = -123456;
    int yr = -123456;
    cin >> n;

    while (n--) {
        int a, b;
        cin >> a >> b;
        if (a < xl)
            xl = a;
        if (b < yl)
            yl = b;
        if (a > xr)
            xr = a;
        if (b > yr)
            yr = b;
    }

    cout << (xr - xl) * (yr - yl);
}
