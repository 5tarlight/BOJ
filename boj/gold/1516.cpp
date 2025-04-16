#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }
template <class OStream, class T> OStream &operator<<(OStream &os, const std::vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <class OStream, class T, class U> OStream &operator<<(OStream &os, const std::pair<T, U> &pa) { return os << '(' << pa.first << ',' << pa.second << ')'; }
#ifdef YEAHx4
#define dbg(x) std::cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
#else
#define dbg(x) ((void)0)
#endif

int main() {
    fio();

    int n;
    cin >> n;
    vector<int> time(n + 1);
    vector<int> deg(n + 1, 0);
    vector<int> v[n + 1];

    for (int i = 1; i <= n; i++) {
        cin >> time[i];
        while (true) {
            int x; cin >> x;
            if (x == -1) break;
            deg[i]++;
            v[x].push_back(i);
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (deg[i] == 0)
            q.push(i);

    vector<int> ans(n + 1, 0);

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        ans[x] += time[x];
        for (int i : v[x]) {
            deg[i]--;
            ans[i] = max(ans[i], ans[x]);
            if (deg[i] == 0)
                q.push(i);
        }
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << endl;
}
