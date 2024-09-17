#include "bits/stdc++.h"

using namespace std;

class UnionFind {
public:
    vector<int> parent;
    vector<int> rank;

    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX] += 1;
            }
        }
    }

    bool connected(int x, int y) { return find(x) == find(y); }
};


int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> adj[n];

    UnionFind uf(n);
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int x;
            cin >> x;
            pq.push({ x, { i, j }});
        }
    }

    while (!pq.empty()) {
        auto [c, p] = pq.top();
        auto [i, j] = p;
        pq.pop();

        if (uf.connected(i, j)) continue;
        adj[i].push_back(j);
        adj[j].push_back(i);
        uf.unite(i, j);
    }

    for (auto v : adj) {
        cout << v.size() << ' ';
        sort(v.begin(), v.end());
        for (int x : v)
            cout << x + 1 << ' ';
        cout << '\n';
    }
}
