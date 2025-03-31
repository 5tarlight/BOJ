#include <bits/stdc++.h>
using namespace std;
void fio() { cin.tie(nullptr); ios::sync_with_stdio(false); }
template <class OStream, class T> OStream &operator<<(OStream &os, const vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <class OStream, class T, class U> OStream &operator<<(OStream &os, const pair<T, U> &pa) { return os << '(' << pa.first << ',' << pa.second << ')'; }
#ifdef YEAHx4
#define dbg(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
#else
#define dbg(x) ((void)0)
#endif

using ll = long long;
constexpr ll MOD = 1e9 + 7;

int main() {
    fio();

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    ll two[n + 1];
    two[0] = 1;
    for (int i = 1; i <= n; i++)
        two[i] = (two[i - 1] * 2) % MOD;

    ll p = 0, m = 0;
    for (int i = n - 1; i > 0; i--) {
        p += (two[i] - 1) * a[i];
        p %= MOD;
        m += (two[i] - 1) * a[n - i - 1];
        m %= MOD;
    }

    cout << (p - m + MOD) % MOD;
}
