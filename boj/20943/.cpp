#include "bits/stdc++.h"

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    map<pair<int, int>, int> cnt;

    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        int g = gcd(abs(a), abs(b));
        a /= g;
        b /= g;

        if (a < 0 || (a == 0 && b < 0)) {
            a = -a;
            b = -b;
        }

        cnt[{a, b}] += 1;
    }

    long long total = 1LL * n * (n - 1) / 2;
    long long dup = 0;

    for (auto &[key, c] : cnt) {
        dup += 1LL * c * (c - 1) / 2;
    }

    cout << total - dup << '\n';
}
