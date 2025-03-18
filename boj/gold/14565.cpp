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
#define dbg(x) std::cout << BRIGHT_CYAN << #x << COLOR_RESET << " = " << (x) << NORMAL_FAINT << " (L" << __LINE__ << ") " << __FILE__ << COLOR_RESET << std::endl
#define dbgif(cond, x) ((cond) ? std::cerr << BRIGHT_CYAN << #x << COLOR_RESET << " = " << (x) << NORMAL_FAINT << " (L" << __LINE__ << ") " << __FILE__ << COLOR_RESET << std::endl : std::cerr)
#else
#define dbg(x) ((void)0)
#define dbgif(cond, x) ((void)0)
#endif

long long eua(long long a, long long b) {
  long long x1, y1, r1;
  long long x2, y2, r2;

  if (a == b || b == 0) {
    x1 = 1; y1 = 0; r1 = a;
  } else {
    x1 = 1; y1 = 0; r1 = a;
    x2 = 0; y2 = 1; r2 = b;

    while (r2) {
      auto q = r1 / r2;

      auto xt = x1 - q * x2;
      auto yt = y1 - q * y2;
      auto rt = r1 - q * r2;

      x1 = x2; y1 = y2; r1 = r2;
      x2 = xt; y2 = yt; r2 = rt;
    }
  }

  if (r1 != 1) return -1;

  while (y1 < 0) y1 += a;

  return y1;
}

int main() {
  long long n, a;
  cin >> n >> a;
  cout << n - a << ' ' << eua(n, a);
}
