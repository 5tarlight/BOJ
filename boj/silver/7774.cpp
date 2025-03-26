#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); ios::sync_with_stdio(false); }
template <class OStream, class T> OStream &operator<<(OStream &os, const std::vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <class OStream, class T, class U> OStream &operator<<(OStream &os, const std::pair<T, U> &pa) { return os << '(' << pa.first << ',' << pa.second << ')'; }
#ifdef YEAHx4
#define dbg(x) std::cout << #x << " = " << (x) << " (L" << __LINE__ << ")"<< endl
#else
#define dbg(x) ((void)0)
#endif

int main() {
  fio();

  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  sort(a.begin(), a.end(), greater<>());
  sort(b.begin(), b.end(), greater<>());

  dbg(a); dbg(b);

  int cntA = 0, cntB = a[0];
  int aIdx = 1;
  for (int i = 0; i < m; i++) {
    dbg(cntA); dbg(cntB);
    if (cntB) {
        cntB--;
        cntA += b[i];
    } else {
        if (aIdx < n) {
            cntA--;
            cntB += a[aIdx++] - 1;
            cntA += b[i];
        } else {
            break;
        }
    }
  }

  cout << cntA;
}
