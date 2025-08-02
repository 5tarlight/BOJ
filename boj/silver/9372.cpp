#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

class DSU {
public:
    vector<int> parent;
    int size;

    DSU(int n) : size(n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        return (parent[x] == x) ? x : (parent[x] = find(parent[x]));
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        parent[x] = y;
    }
};

int main() {
    fio();

    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        DSU dsu(n);

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            int u, v; cin >> u >> v;
            --u; --v;
            if (dsu.find(u) != dsu.find(v)) {
                dsu.unite(u, v);
                ans++;
            }
        }

        cout << ans << '\n';
    }
}
