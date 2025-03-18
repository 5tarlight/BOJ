#include "bits/stdc++.h"

using namespace std;

struct fast_ios { fast_ios(){ cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(20); }; } fast_ios_;

const std::vector<std::pair<int, int>> grid_dxs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

template <class OStream, class T> OStream &operator<<(OStream &os, const std::vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <class OStream, class T, class U> OStream &operator<<(OStream &os, const std::pair<T, U> &pa) { return os << '(' << pa.first << ',' << pa.second << ')'; }
template <class T1, class T2> std::pair<T1, T2> operator+(const std::pair<T1, T2> &l, const std::pair<T1, T2> &r) { return std::make_pair(l.first + r.first, l.second + r.second); }
template <class T1, class T2> std::pair<T1, T2> operator-(const std::pair<T1, T2> &l, const std::pair<T1, T2> &r) { return std::make_pair(l.first - r.first, l.second - r.second); }

#ifdef YEAHx4
const string COLOR_RESET = "\033[0m", BRIGHT_GREEN = "\033[1;32m", BRIGHT_RED = "\033[1;31m", BRIGHT_CYAN = "\033[1;36m", NORMAL_CROSSED = "\033[0;9;37m", RED_BACKGROUND = "\033[1;41m", NORMAL_FAINT = "\033[0;2m";
#define dbg(x) std::cerr << BRIGHT_CYAN << #x << COLOR_RESET << " = " << (x) << NORMAL_FAINT << " (L" << __LINE__ << ") " << __FILE__ << COLOR_RESET << std::endl
#define dbgif(cond, x) ((cond) ? std::cerr << BRIGHT_CYAN << #x << COLOR_RESET << " = " << (x) << NORMAL_FAINT << " (L" << __LINE__ << ") " << __FILE__ << COLOR_RESET << std::endl : std::cerr)
#else
#define dbg(x) ((void)0)
#define dbgif(cond, x) ((void)0)
#endif

int solve(int k, int c) {
    vector<int> quot;

    int t1 = k;
    int t2 = c;
    int t3 = k % c;

    while (t3) {
        quot.push_back(t1 / t2);
        t1 = t2;
        t2 = t3;
        t3 = t1 % t2;
    }

    if (t2 != 1) return -1;

    vector<long long> cc, ck;
    ck.push_back(1); ck.push_back(0);
    cc.push_back(0); cc.push_back(1);

    for (int q : quot) {
        long long tmp1 = ck[ck.size() - 2] - (long long)q * ck[ck.size() - 1];
        long long tmp2 = cc[cc.size() - 2] - (long long)q * cc[cc.size() - 1];

        ck.push_back(tmp1);
        cc.push_back(tmp2);
    }

    auto xk = ck[ck.size() - 1];
    auto xc = cc[cc.size() - 1];

    while (xc <= 0 || xk >= 0) {
        xc += k;
        xk -= c;
    }

    if (xc > 1000000000) return -1;
    return (int)xc;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k, c;
        cin >> k >> c;
        int ans = solve(k, c);
        if (ans == -1) cout << "IMPOSSIBLE\n";
        else cout << ans << '\n';
    }
}
