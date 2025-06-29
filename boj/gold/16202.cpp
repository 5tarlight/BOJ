#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

struct dsu {
    vector<int> p, r;
    dsu(int n): p(n+1), r(n+1,0) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        return p[x]==x ? x : p[x]=find(p[x]);
    }
    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a==b) return false;
        if (r[a]<r[b]) swap(a,b);
        p[b]=a;
        if (r[a]==r[b]) r[a]++;
        return true;
    }
};

int main() {
    fio();

    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int,int>> e(m+1);
    for (int i = 1; i <= m; i++) cin >> e[i].first >> e[i].second;

    vector<bool> rem(m+1);
    vector<long long> res;
    res.reserve(k);

    for (int t = 1; t <= k; t++) {
        dsu d(n);
        long long c = 0;
        int u = 0, del = -1;
        for (int i = 1; i <= m; i++) {
            if (rem[i]) continue;
            auto [a, b] = e[i];
            if (d.unite(a, b)) {
                c += i;
                if (del == -1) del = i;
                if (++u == n-1) break;
            }
        }
        if (u < n-1) {
            while (t++ <= k) res.push_back(0);
            break;
        }
        res.push_back(c);
        rem[del] = 1;
    }

    for (int r : res)
        cout << r << ' ';
}
