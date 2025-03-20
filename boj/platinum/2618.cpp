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

constexpr int MAX = 1010;

int n, w, dp[MAX][MAX];
pair<int, int> event[MAX];

int dist(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int solve(int a, int b) {
    if (a == w || b == w) return 0;
    if (dp[a][b] != -1) return dp[a][b];

    int next = max(a, b) + 1;
    int d1 = (a == 0) ? dist({1, 1}, event[next]) : dist(event[a], event[next]);
    int d2 = (b == 0) ? dist({n, n}, event[next]) : dist(event[b], event[next]);

    return dp[a][b] = min(solve(next, b) + d1, solve(a, next) + d2);
}

void route(int a, int b) {
    if (a == w || b == w) return;
    int next = max(a, b) + 1;
    int d1 = (a == 0) ? dist({1, 1}, event[next]) : dist(event[a], event[next]);
    int d2 = (b == 0) ? dist({n, n}, event[next]) : dist(event[b], event[next]);

    if (solve(next, b) + d1 < solve(a, next) + d2) {
        cout << 1 << '\n';
        route(next, b);
    } else {
        cout << 2 << '\n';
        route(a, next);
    }
}

int main() {
    cin >> n >> w;
    for (int i = 1; i <= w; i++)
        cin >> event[i].first >> event[i].second;

    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0) << '\n';
    route(0, 0);
}
