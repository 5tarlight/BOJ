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

int main() {
    fio();

    int n;
    cin >> n;
    ll bit[n];
    memset(bit, 0, sizeof(bit));
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        while (k--) {
            int x;
            cin >> x;
            bit[i] |= (1LL << x);
        }
    }

    int m;
    cin >> m;
    while (m--) {
        int k;
        cin >> k;
        int ans = 0;
        ll tmp = -1;
        while (k--) {
            int x;
            cin >> x;
            tmp ^= (1LL << x);
        }

        for (int i = 0; i < n; i++) {
            if ((bit[i] & tmp) == 0) {
                ans++;
            }
        }

        cout << ans << '\n';
    }
}
