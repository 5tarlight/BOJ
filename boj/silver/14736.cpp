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
    int n, k, a;
    cin >> n >> k >> a;
    int t[n], s[n];
    for (int i = 0; i < n; i++)
        cin >> t[i] >> s[i];
    int ans = 1e9;

    for (int i = 0; i < n; i++) {
        int left = k;
        int tmp = 0;
        while (left > 0) {
            for (int j = 0; j < t[i] && left > 0; j++) {
                left -= a;
                tmp++;
            }
            if (left > 0)
                tmp += s[i];
        }

        ans = min(ans, tmp);
    }

    cout << ans;
}
