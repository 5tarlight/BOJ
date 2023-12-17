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

    bool filter[246'913];
    for (int i = 0; i < 246913; i++)
        filter[i] = isPrime(i);

    while (true) {
        int n;
        cin >> n;
        if (n == 0)
            return 0;

        int cnt = 0;
        for (int i = n + 1; i <= 2 * n; i++)
            if (filter[i])
                cnt++;

        cout << cnt << '\n';
    }
}
