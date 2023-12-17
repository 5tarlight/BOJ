#include <iostream>

using namespace std;

bool isPrime(long long x) {
    if (x <= 1)
        return false;

    for (long long i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long ans = n;
        while (!isPrime(ans))
            ans++;
        cout << ans << '\n';
    }
}
