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

constexpr int MOD = 1e9 + 7;

int main() {
    fio();

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        vector<int> v;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                v.push_back(i);

        if (v.empty()) {
            cout << "-1\n";
            continue;
        }

        long long ans = 1;
        for (int i = 1; i < v.size(); i++) {
            int tmp = v[i] - v[i - 1];
            if (tmp == 0) continue;
            ans *= tmp % MOD;
            ans %= MOD;
        }

        cout << ans << '\n';
    }
}
