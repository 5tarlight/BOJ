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

using ll = long long;

pair<ll, ll> solve(ll r, ll s, ll f) {
  ll r1, s1, t1;
  ll r2, s2, t2;

  r1 = 1; s1 = 0; t1 = r;
  r2 = 0; s2 = 1; t2 = s;

  while (t2) {
    ll q = t1 / t2;
    ll rt = r1 - q * r2;
    ll st = s1 - q * s2;
    ll tt = t1 - q * t2;
    r1 = r2; s1 = s2; t1 = t2;
    r2 = rt; s2 = st; t2 = tt;
  }

  t1 = abs(t1);

  if(r * r1 + s * s1 < 0) {
    r1 = -r1;
    s1 = -s1;
  }

  r1 *= f; r1 /= t1;
  s1 *= f; s1 /= t1;

  while(r1 < 1 || s1 < 1) {
    r1 += -s / t1;
    s1 += r / t1;
  }

  while(r1 - (-s / t1) >= 1 && s1 - (r / t1) >= 1) {
    r1 -= -s / t1;
    s1 -= r / t1;
  }

  return {r1, s1};
}

int main() {
  fast_ios{};
  int t;
  cin >> t;
  while (t--) {
    int r, s, q;
    cin >> r >> s >> q;
    auto [a, b] = solve(r, s, q);
    cout << a << ' ' << b << '\n';
  }
}
