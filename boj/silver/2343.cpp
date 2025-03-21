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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    int l = 1, r = 1e9 + 1;
    while (l < r) {
        int mid = (l + r) / 2;
        int tmp = mid;

        int cnt = 1;
        for (auto x : a) {
            if (x > mid) {
                cnt = 1e9;
                break;
            }

            if (tmp >= x) {
                tmp -= x;
            } else {
                tmp = mid - x;
                cnt++;
            }
        }

        if (cnt <= m) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << l;
}
