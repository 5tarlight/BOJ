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

int div(int x) {
    int ans = 1;
    for (int i = 2; i * i <= x; i++) {
        int cnt = 0;
        while (x % i == 0) {
            cnt++;
            x /= i;
        }

        if (cnt & 1) ans *= i;
    }

    return ans * x;
}

int main() {
    fio();

    int n, m;
    int ans = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int x = div(i);
        ans += (int)sqrt(m / x);
    }

    cout << ans;
}
