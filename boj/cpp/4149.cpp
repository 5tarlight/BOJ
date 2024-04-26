#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

typedef unsigned long long ull;
typedef __int128 lll;

ull power(lll x, lll y, lll mod) { // x^y % mod
    x %= mod;
    lll ret = 1;
    while (y > 0) {
        if (y & 1)
            ret = (ret * x) % mod;

        x = (x * x) % mod;
        y >>= 1;
    }

    return (ull)ret;
}

bool isCoprime(ull n, ull a) {
    if (a % n == 0)
        return true;

    ull k = n - 1;
    while (true) {
        ull temp = power(a, k, n);

        if (temp == n - 1)
            return true;
        if (k & 1)
            return (temp == 1 || temp == n - 1);
        k >>= 1;
    }
}

bool isPrime(ull n) {
    if (n == 1 || (n & 1) == 0)
        return false;
    else if (n < 4)
        return true;

    ull a[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };
    for (ull i : a)
        if (!isCoprime(n, i))
            return false;
    return true;
}

ull gcd(ull a, ull b) {
    if (a < b)
        swap(a, b);

    while (b != 0) {
        ull r = a % b;
        a = b;
        b = r;
    }

    return a;
}

namespace yeahx4 {
    lll abs(lll x) {
        return x < 0 ? -x : x;
    }
}


ull getFactor(lll n) {
    if ((n & 1) == 0)
        return 2;
    else if (isPrime(n))
        return n;

    lll x = rand() % (n - 2) + 2;
    lll y = x;
    lll c = rand() % 10 + 1;
    lll g = 1;

    while (g == 1) {
        x = (x * x % n + c) % n;
        y = (y * y % n + c) % n;
        y = (y * y % n + c) % n;
        g = gcd(yeahx4::abs(x - y), n);
    }

    if (isPrime(g))
        return g;
    else
        return getFactor(g);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ull n;
    cin >> n;

    vector<ull> ans;
    while (n > 1) {
        ull factor = getFactor(n);
        ans.push_back(factor);
        n /= factor;
    }

    sort(ans.begin(), ans.end());

    for (ull i : ans)
        cout << i << '\n';
}
