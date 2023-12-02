#include <iostream>

using namespace std;

bool isPrime(int n) {
    if (n == 1)
        return false;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;
    int sum = 0;
    int f;
    for (int i = m; i <= n; i++) {
        if (isPrime(i)) {
            if (sum == 0)
                f = i;
            sum += i;
        }
    }

    if (sum == 0) {
        cout << -1;
    } else {
        cout << sum << '\n' << f;
    }
}
