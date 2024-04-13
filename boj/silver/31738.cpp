#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    long long n, m;
    cin >> n >> m;

    if (n >= m)
        cout << 0;
    else {
        long long result = 1;
        for (long long i = n; i > 1; i--) {
            result *= i;
            result %= m;

            if (result == 0) {
                cout << 0;
                return 0;
            }
        }

        cout << result;
    }
}
