#include "bits/stdc++.h"

using namespace std;

int parent[10001];

int find(int x) {
    if (parent[x] == x)
        return x;
    else
        return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
    int pa = find(a);
    int pb = find(b);

    if (pa != pb) {
        parent[pa] = pb;
    }
}

int p, q;

struct Cmp {
    bool operator()(const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b) {
        if (a.first == b.first) {
            if (
                a.second.first == p && a.second.second == q ||
                a.second.first == q && a.second.second == p
            )
                return false;
            else if (
                    b.second.first == p && b.second.second == q ||
                    b.second.first == q && b.second.second == p
            )
                return true;
        }

        return a > b;
    }
};

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m >> p >> q;
        for (int i = 0; i <= n; i++)
            parent[i] = i;

        priority_queue<
                pair<int, pair<int, int>>,
                vector<pair<int, pair<int, int>>>,
                Cmp
        > pq;

        while (m--) {
            int a, b, c;
            cin >> a >> b >> c;
            pq.push({ c, { a, b }});
        }

        bool found = false;
        while (!pq.empty()) {
            auto [cost, pp] = pq.top();
            auto [a, b] = pp;
            pq.pop();

            if (find(a) != find(b)) {
                unite(a, b);

                if (a == p && b == q || a == q && b == p) {
                    found = true;
                    break;
                }
            }
        }

        if (found)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
