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
    int n, p, q;
    cin >> n >> p >> q;
    int a[n], b[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int cnt = 0;
    int ans[n];
    fill(ans, ans + n, 0);
    for (int i = 0; i < n; i++) {
        int tmp = 0;
        if (a[i] == b[i]) continue;
        if (p < q && a[i] < b[i]) {
            cout << "NO";
            return 0;
        } else if (p > q && a[i] > b[i]) {
            cout << "NO";
            return 0;
        }

        while (a[i] != b[i]) {
            cnt++;
            tmp++;
            a[i] += p;
            b[i] += q;

            if (cnt >= 10000) {
                cout << "NO";
                return 0;
            }
        }

        ans[i] = tmp;
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) cout << ans[i] << ' ';
}
