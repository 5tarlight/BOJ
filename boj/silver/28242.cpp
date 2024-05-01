#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 1; i * i <= n; i++) {
        if (n % i != 0)
            continue;

        int a = i;
        int c = n / i;

        for (int j = 1; j * j <= n + 2; j++) {
            if ((n + 2) % j != 0)
                continue;

            int b = j;
            int d = -(n + 2) / j;

            if (a * d + b * c == n + 1) {
                cout << a << " " << b << " " << c << " " << d << endl;
                return 0;
            }

            b = -b;
            d = -d;

            if (a * d + b * c == n + 1) {
                cout << a << " " << b << " " << c << " " << d << endl;
                return 0;
            }
        }
    }

    cout << -1;
}
