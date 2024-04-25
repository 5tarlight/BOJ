#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

class Frac {
public:
    long long num, den;

    Frac(long long num, long long den) {
        long long g = gcd(num, den);
        this->num = num / g;
        this->den = den / g;
    }

    Frac operator+(const Frac &other) const {
        return Frac(num * other.den + other.num * den, den * other.den);
    }

    Frac operator-(const Frac &other) const {
        return Frac(num * other.den - other.num * den, den * other.den);
    }

    Frac reverse() {
        return Frac(den, num);
    }
};

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    Frac prev{a[n - 1], 1};
    for (int i = n - 2; i >= 0; i--)
        prev = Frac(a[i], 1) + prev.reverse();

    Frac ans = Frac(1, 1) - prev.reverse();
    if (ans.den != 1)
        cout << ans.num << ' ' << ans.den;
    else
        cout << ans.num;
}
