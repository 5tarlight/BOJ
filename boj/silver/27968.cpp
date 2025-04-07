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

int main() {
    fio();

    int n, m;
    cin >> n >> m;
    long long a[m + 1], sum[m + 1];
    sum[0] = 0;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }

    while (n--) {
        long long x;
        cin >> x;
        int idx = upper_bound(sum, sum + m + 1, x - 1) - sum;
        if (idx > m) cout << "Go away!\n";
        else cout << idx << '\n';
    }
}
