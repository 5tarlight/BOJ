#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int d, k;
    cin >> d >> k;
    int fibo[d];
    fibo[1] = fibo[2] = 1;
    for (int i = 3; i < d; i++)
        fibo[i] = fibo[i - 1] + fibo[i - 2];

    int ax = fibo[d - 2];
    int bx = fibo[d - 1];
    int a = 1;

    while (true) {
        int b = (k - a * ax) / bx;
        if (a * ax + b * bx == k) {
            cout << a << '\n' << b;
            break;
        }
        a++;
    }
}
