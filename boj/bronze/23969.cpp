#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); ios::sync_with_stdio(false); }
template <class OStream, class T> OStream &operator<<(OStream &os, const std::vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <class OStream, class T, class U> OStream &operator<<(OStream &os, const std::pair<T, U> &pa) { return os << '(' << pa.first << ',' << pa.second << ')'; }
#ifdef YEAHx4
#define dbg(x) std::cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
#else
#define dbg(x) ((void)0)
#endif

int main() {
    fio();

    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = n - 1; i >= 1 && k > 0; i--) {
        for (int j = 0; j < i && k > 0; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                k--;
            }
        }
    }

    if (k != 0)
        cout << -1;
    else
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
}
