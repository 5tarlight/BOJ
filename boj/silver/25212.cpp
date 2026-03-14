#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

struct frac {
    long long a, b;

    frac(long long a, long long b): a(a), b(b) {
        long long g = gcd(abs(a), abs(b));
        this->a = a / g;
        this->b = b / g;
    }
};
frac addFrac(frac x, frac y) {
    long long new_a = x.a * y.b + y.a * x.b;
    long long new_b = x.b * y.b;
    return frac(new_a, new_b);
}

bool isGreaterOrEqual(frac a, frac b) {
    return a.a * b.b >= b.a * a.b;
}

vector<int> aa;
int n;

int main() {
    fio();

    if (!(cin >> n)) return 0;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        aa.push_back(x);
    }

    int ans = 0;
    frac min_f(99, 100);
    frac max_f(101, 100);

    for (int i = 1; i < (1 << n); i++) {
        frac sum(0, 1);

        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                sum = addFrac(sum, frac(1, aa[j]));
            }
        }

        if (isGreaterOrEqual(sum, min_f) && isGreaterOrEqual(max_f, sum)) {
            ans++;
        }
    }

    cout << ans << "\n";
    return 0;
}
