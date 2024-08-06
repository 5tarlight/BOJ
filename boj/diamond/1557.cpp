#include <iostream>

using namespace std;

int mobius[1000001];

long long find(long long x) {
    auto ans = 0LL;
    for (auto i = 1LL; i * i <= x; i++)
        ans += mobius[i] * (x / (i * i));
    return ans;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    mobius[1] = 1;
    for (int i = 1; i <= 1000000; i++)
        for (int j = 2 * i; j <= 1000000; j += i)
            mobius[j] -= mobius[i];

    long long n;
    cin >> n;
    long long l = 0, r = 1e10;

    while (l < r - 1) {
        if (auto mid = (l + r) / 2; find(mid) < n)
            l = mid;
        else
            r = mid;
    }

    cout << r;
}
