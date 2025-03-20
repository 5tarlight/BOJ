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

int n, ans;
vector<string> words;

struct Trie {
  bool end;
  bool root;
  int child;
  Trie *nxt[26];

  Trie(bool root = false) : end(false), root(root), child(0) {
    memset(nxt, 0, sizeof(nxt));
  }

  ~Trie() {
    for (int i = 0; i < 26; i++)
      delete nxt[i];
  }

  void insert(const char *key) {
    if (*key == '\0')
      end = true;
    else {
      int cur = *key - 'a';
      if (nxt[cur] == NULL) {
        nxt[cur] = new Trie();
        child++;
      }

      nxt[cur]->insert(key + 1);
    }
  }

  void find(const char* s) {
    if (*s == '\0') return;

    int cur = *s - 'a';
    if (root) ans++;
    else {
      if (child > 1 || end) ans++;
    }

    nxt[cur]->find(s + 1);
  }
};

int main() {
  fast_ios{};

  while (cin >> n) {
    Trie trie(true);
    words.clear();

    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      words.push_back(s);
      trie.insert(words[i].c_str());
    }

    int sum = 0;
    for (int i = 0; i < words.size(); i++) {
      ans = 0;
      trie.find(words[i].c_str());
      sum += ans;
    }

    double ret = (double)sum / n;
    cout << fixed << setprecision(2) << ret << '\n';
  }
}
