#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    if (n == 1) {
        cout << 4;
        return 0;
    } else if (n == 2) {
        cout << 6;
        return 0;
    }

    long long fibo[n];
    fibo[0] = 1;
    fibo[1] = 1;
    for (int i = 2; i < n; i++)
        fibo[i] = fibo[i - 1] + fibo[i - 2];

    cout << 2 * (fibo[n - 1] + fibo[n - 2]) + 2 * fibo[n - 1];
}
