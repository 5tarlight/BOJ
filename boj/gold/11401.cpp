#include <iostream>

using namespace std;

#define DIV 1000000007

long long tmp;
long long power(long long a, long long m) {
    if (m == 0)
        return 1;

    tmp = power(a, m / 2) % DIV;

    if (m % 2 == 1)
        return tmp * tmp % DIV * a % DIV;
    else
        return tmp * tmp % DIV;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    long long ans;
    if (k == 1)
        ans = n;
    else if (k == 0 || n == k)
        ans = 1;
    else if (n - k == 1)
        ans = n;
    else {
        long long a = 1;
        long long b = 1;

        for (int i = n; i >= n - k + 1; i--)
            a = a * i % DIV;
        for (int i = 1; i <= k; i++)
            b = b * i % DIV;

        ans = ((a % DIV) * power(b, DIV - 2) % DIV) % DIV;
    }

    cout << ans;
}
