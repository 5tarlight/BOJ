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
    int n;
    cin >> n;
    vector<int> order(n);
    for (int i = 0; i < n; i++) {
        cin >> order[i];
        order[i]--;
    }

    vector<int> ans(n);
    for (int i = 0; i < n; i++) cin >> ans[i];

    vector<int> prev(n);
    for (int step = 0; step < 3; step++) {
        for (int i = 0; i < n; i++) {
            prev[i] = ans[order[i]];
        }
        ans = prev;
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << '\n';
}
