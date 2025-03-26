#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); ios::sync_with_stdio(false); }
template <class OStream, class T> OStream &operator<<(OStream &os, const std::vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <class OStream, class T, class U> OStream &operator<<(OStream &os, const std::pair<T, U> &pa) { return os << '(' << pa.first << ',' << pa.second << ')'; }
#ifdef YEAHx4
#define dbg(x) std::cout << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl
#else
#define dbg(x) ((void)0)
#endif

int main() {
  fio();

  double a, b; cin >> a >> b;
  cout << (int)(abs(a / b - 1) * 2);
}
