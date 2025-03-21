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
    int n, k;
    cin >> n >> k;
    int coin[n];
    for (int i = 0; i < n; i++) cin >> coin[i];
    int dp[k + 1];

    dp[0] = 0;
    for (int i = 1; i <= k; i++) {
        dp[i] = 1e9;
        for (int j = 0; j < n; j++) {
            if (i - coin[j] >= 0) {
                dp[i] = min(dp[i], dp[i - coin[j]] + 1);
            }
        }
    }

    cout << (dp[k] == 1e9 ? -1 : dp[k]);
}
