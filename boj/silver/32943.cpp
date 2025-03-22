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

int main() {
    fio();
    int x, c, k;
    cin >> x >> c >> k;
    vector<pair<int, pair<int, int>>> v(k);
    for (int i = 0; i < k; i++) {
        cin >> v[i].first >> v[i].second.first >> v[i].second.second;
    }

    sort(v.begin(), v.end());

    bool book[c + 1];
    int pos[x + 1];
    memset(book, false, sizeof(book));
    memset(pos, -1, sizeof(pos));

    for (int i = 0; i < k; i++) {
        auto [_, p] = v[i];
        auto [s, n] = p;
        if (book[s]) continue;
        if (pos[n] != -1) {
            book[pos[n]] = false;
        }

        book[s] = true;
        pos[n] = s;
    }

    for (int i = 1; i <= x; i++) {
        if (pos[i] != -1) {
            cout << i << ' ' << pos[i] << '\n';
        }
    }
}
