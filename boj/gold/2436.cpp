#include <iostream>

using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;
    int mul = b / a;
    int aa, bb;
    int sum = 1e9;
    for (int i = 1; i * i <= mul; i++) {
        if (mul % i == 0) {
            int taa = mul / i;
            int tbb = i;
            if (gcd(taa, tbb) != 1)
                continue;

            if (sum > taa + tbb) {
                aa = taa;
                bb = tbb;
                sum = taa + tbb;
            }
        }
    }

    cout << bb * a << ' ' << aa * a;
}
