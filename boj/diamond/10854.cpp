#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

typedef unsigned long long ull;
typedef __int128 lll;

ull pow(lll x, lll y, lll mod) {
    x %= mod;
    lll ans = 1;
    while (y) {
        if (y & 1) ans = (ans * x) % mod;
        x = (x * x) % mod;
        y /= 2;
    }

    return (ull)ans;
}

bool check(ull n, ull a) {
    if (a % n == 0) return true;
    ull k = n - 1;

    while (true) {
        ull tmp = pow(a, k, n);

        if (tmp == n - 1) return true;
        if (k & 1) return tmp == 1 || tmp == n - 1;

        k /= 2;
    }
}

bool isPrime(ull n) {
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;

    ull a[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    for (ull v : a)
        if (!check(n, v))
            return false;

    return true;
}

ull gcd(ull a, ull b) {
    if (a < b) swap(a, b);
    while (b) {
        ull t = a % b;
        a = b;
        b = t;
    }

    return a;
}

lll abs(lll x) {
    if (x < 0) return -x;
    else return x;
}

ull find(lll n) {
    if (n % 2 == 0) return 2;
    if (isPrime(n)) return n;

    lll x = rand() % (n - 2) + 2;
    lll y = x;
    lll c = rand() % 10 + 1;
    lll g = 1;

    while (g == 1) {
        x = (x * x % n + c) % n;
        y = (y * y % n + c) % n;
        y = (y * y % n + c) % n;
        g = gcd(::abs(x - y), n);
        if (g == n) return find(n);
    }

    if (isPrime(g)) return g;
    else return find(g);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ull n;
    cin >> n;
    if (n == 1) {
        cout << 1;
        return 0;
    }

    vector<ull> ans;
    while (n > 1) {
        ull div = find(n);
        ans.push_back(div);
        n /= div;
    }

    sort(ans.begin(), ans.end());

    ull a = 1;
    ull mul = 2;

    for (int i = 0; i < ans.size() - 1; i++) {
        if (ans[i] == ans[i + 1]) mul++;
        else a *= mul, mul = 2;
    }

    a *= mul;
    cout << a;
}
