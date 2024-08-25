#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> tree;
vector<int> lazy;

void updateLazy(int l, int r, int node) {
    if (lazy[node] & 1) {
        tree[node] = (r - l + 1) - tree[node];

        if (l != r) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }

        lazy[node] = 0;
    }
}

void updateRange(int s, int e, int l, int r, int node) {
    updateLazy(s, e, node);
    if (r < s || e < l) return;

    if (l <= s && e <= r) {
        tree[node] = (e - s + 1) - tree[node];

        if (s != e) {
            lazy[2 * node] += 1;
            lazy[2 * node + 1] += 1;
        }

        return;
    }

    int mid = (s + e) / 2;
    updateRange(s, mid, l, r, 2 * node);
    updateRange(mid + 1, e, l, r, 2 * node + 1);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query(int s, int e, int l, int r, int node) {
    updateLazy(s, e, node);

    if (r < s || e < l) return 0;

    if (l <= s && e <= r)
        return tree[node];

    int mid = (s + e) / 2;
    return query(s, mid, l, r, 2 * node) + query(mid + 1, e, l, r, 2 * node + 1);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    int height = (int)ceil(log2(n));
    tree = vector<int>(1 << (height + 1));
    lazy = vector<int>(1 << (height + 1));

    while (m--) {
        int o, s, t;
        cin >> o >> s >> t;

        if (o == 0)
            updateRange(1, n, s, t, 1);
        else
            cout << query(1, n, s, t, 1) << '\n';
    }
}
