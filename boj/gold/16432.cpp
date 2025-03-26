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

int n;
vector<int> ans;
vector<int> day[1001];
int ok[1001][10];

bool dfs(int cur, int prev) {
    if (cur == 0) {
        ok[cur][prev] = true;
        return true;
    } else if (ok[cur][prev] == 1) {
        return true;
    } else if (ok[cur][prev] == -1) {
        return false;
    }

    dbg(cur);

    for (int i = 0; i < day[cur].size(); i++) {
        if (day[cur][i] == prev) continue;
        ans[cur] = day[cur][i];
        if (dfs(cur - 1, day[cur][i])) {
            ok[cur][prev] = 1;
            return true;
        } else {
            ok[cur][prev] = -1;
        }
    }

    return false;
}

int main() {
    fio();
    cin >> n;
    ans.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        day[i].resize(x);
        for (int j = 0; j < x; j++) {
            cin >> day[i][j];
        }
    }

    if (dfs(n, 0)) {
        for (int i = 1; i <= n; i++) {
            cout << ans[i] << '\n';
        }
    } else {
        cout << -1;
    }
}
