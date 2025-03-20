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

int main() {
  ll a, b;
  cin >> a >> b;

  if (a == b) {
    cout << 1;
    return 0;
  }

  if (a > b) swap(a, b);

  vector<ll> div;
  for (int i = 1; i * i <= (b - a); i++) {
    if ((b - a) % i == 0) {
      div.push_back(i);
      if (i * i != (b - a)) div.push_back((b - a) / i);
    }
  }

  ll ans = LLONG_MAX;
  ll lcm = LLONG_MAX;

  for (auto d : div) {
    ll r = a % d;
    ll n = d - r;

    ll tmp = (a + n) * (b + n) / d;

    if (tmp < lcm) {
      lcm = tmp;
      ans = n;
    } else if (tmp == lcm && n < ans) {
      ans = n;
    }
  }

  cout << ans;
}
