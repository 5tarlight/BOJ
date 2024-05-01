#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long preciseSqrt(long long x) {
    long long ans = 0;
    for (; ans * ans <= x; ans++);

    return ans - 1;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    long long a, b;
    cin >> a >> b;

    long long cnt = preciseSqrt(b) - preciseSqrt(a);

    if (cnt == 0) {
        cout << "0";
        return 0;
    }

    long long total = b - a;
    long long g = gcd(cnt, total);
    cout << cnt / g << '/' << total / g << '\n';
}
