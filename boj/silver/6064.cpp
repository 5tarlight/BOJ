#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int m, n, x, y;
        cin >> m >> n >> x >> y;
        int max = lcm(m, n);
        int result = -1;

        for (int j = x; j <= max; j += m) {
            int ny = j % n;

            if (ny == 0)
                ny = n;
            if (ny == y) {
                result = j;
                break;
            }
        }

        cout << result << '\n';
    }
}
