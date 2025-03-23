#include "bits/stdc++.h"

using namespace std;

void fio() { cin.tie(nullptr); ios::sync_with_stdio(false); }

template <class OStream, class T> OStream &operator<<(OStream &os, const std::vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <class OStream, class T, class U> OStream &operator<<(OStream &os, const std::pair<T, U> &pa) { return os << '(' << pa.first << ',' << pa.second << ')'; }

#ifdef YEAHx4
#define dbg(x) std::cout << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl
#else
#define dbg(x) ((void)0)
#endif

unordered_map<char, int> hole = {
        {'A', 1},
        {'B', 2},
        {'D', 1},
        {'O', 1},
        {'P', 1},
        {'Q', 1},
        {'R', 1},
        {'a', 1},
        {'b', 1},
        {'d', 1},
        {'e', 1},
        {'g', 1},
        {'o', 1},
        {'p', 1},
        {'q', 1},
        {'@', 1}
};

int main() {
    string s;
    getline(cin, s);

    int ans = 0;
    for (char c : s) {
        if (hole.find(c) != hole.end()) {
            ans += hole[c];
        }
    }

    cout << ans;
}
