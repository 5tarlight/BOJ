#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

constexpr int MOD = 1e9 + 7;

long long p(int n) {
    if (n == 0) return 1;
    long long tmp = p(n / 2);
    tmp = tmp * tmp % MOD;
    if (n & 1) tmp = tmp * 26 % MOD;
    return tmp;
}

int main() {
    fio();

    int l, u;
    cin >> l >> u;

    bool isEven = true;
    for (int i = l; i <= u; i++) {
        if (i == 1 || i == 2) isEven = !isEven;
    }

    l -= 2; u -= 2;

    long long cnt = 0;
    for (int i = l; i <= u; i++) {
        cnt = (cnt + p((i + 1) / 2)) % MOD;
    }

    if (!isEven) cout << 'H' << '\n';
    else cout << 'A' << '\n';
    cout << cnt;
}
