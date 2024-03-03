#include <iostream>

using namespace std;

int asum = 0;
int bsum = 0;

int gcd(int a, int b) {
    while (b) {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        asum += a;
    }
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        bsum += b;
    }

    int g = gcd(asum, bsum);
    int a = bsum / g;
    int b = asum / g;

    cout << a << ' ' << b;
}

