#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;
    int n;
    cin >> n;
    long long num[n];
    for (int i = 0; i < n; i++)
        cin >> num[i];

    long long dec = 0;
    long long base = 1;
    for (int i = n - 1; i >= 0; i--) {
        dec += num[i] * base;
        base *= a;
    }

    long long temp = dec;
    int digit = 0;
    while (temp) {
        digit++;
        temp /= b;
    }

    base = 1;
    for (int i = 0; i < digit - 1; i++)
        base *= b;

    for (int i = 0; i < digit; i++) {
        cout << dec / base << ' ';
        dec %= base;
        base /= b;
    }
}
