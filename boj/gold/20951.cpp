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

using ll = long long;
constexpr ll MOD = 1e9 + 7;
int n, m;
vector<int> adj[100001];
ll dp[100001][8];

ll dfs(int x, int cnt) {
    if (dp[x][cnt] != -1) return dp[x][cnt];
    if (cnt == 7) return 1;

    ll ret = 0;
    for (int y : adj[x]) {
        ret += dfs(y, cnt + 1);
        ret %= MOD;
    }

    return dp[x][cnt] = ret;
}

int main() {
    fio();
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;

    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += dfs(i, 0);
        ans %= MOD;
    }

    cout << ans;
}
