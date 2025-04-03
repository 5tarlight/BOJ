#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); ios::sync_with_stdio(false); }
template <class OStream, class T> OStream &operator<<(OStream &os, const std::vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <class OStream, class T, class U> OStream &operator<<(OStream &os, const std::pair<T, U> &pa) { return os << '(' << pa.first << ',' << pa.second << ')'; }
#ifdef YEAHx4
#define dbg(x) std::cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
#else
#define dbg(x) ((void)0)
#endif

using ll = long long;

bool isQuad(ll x) {
    ll  s = sqrt(x);
    return s * s == x;
}

int main() {
    fio();

    ll n;
    cin >> n;
    if (isQuad(n)) {
        cout << -1;
        return 0;
    }

    dbg(n);

    int ans = 0;
    for (ll i = 1; 2 * i * i <= n; ++i) {
        if (isQuad(n - i * i))
            ans++;
    }

    for (ll i = 1; i * i <= n; ++i) {
        if (n % i != 0) continue;
        ll tmp = n / i;
        if ((i + tmp) % 2 == 0 && abs(i - tmp) % 2 == 0)
            ans++;
    }

    cout << ans;
}
