#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;

    if (n <= 28) {
        if (n <= 1)
            cout << 1;
        else if (n <= 3)
            cout << 2;
        else if (n <= 6)
            cout << 3;
        else if (n <= 10)
            cout << 4;
        else if (n <= 15)
            cout << 5;
        else if (n <= 21)
            cout << 6;
        else
            cout << 7;

        return 0;
    }

    long long stair = 6 * 7 / 2;
    n -= stair;

    long long ans;
    if (n % 7 == 0)
        ans = n / 7;
    else
        ans = n / 7 + 1;

    cout << ans + 6;
}
