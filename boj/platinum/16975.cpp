#include "bits/stdc++.h"

using namespace std;

using ll = long long;
#define LEN 1000001

ll a[LEN];
ll tree[4 * LEN];
ll lazy[4 * LEN];

void init(int node, int s, int e) {
    if (s == e) {
        tree[node] = a[s];
        return;
    }

    int mid = (s + e) / 2;
    init(2 * node, s, mid);
    init(2 * node + 1, mid + 1, e);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void propagate(int node, int s, int e) {
    if (lazy[node] != 0) {
        tree[node] += (e - s + 1) * lazy[node];
        if (s != e) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

ll query(int node, int s, int e, int l, int r) {
    propagate(node, s, e);
    if (e < l || s > r) return 0;
    if (s >= l && e <= r) return tree[node];

    int mid = (s + e) / 2;
    ll left = query(node * 2, s, mid, l, r);
    ll right = query(node * 2 + 1, mid + 1, e, l, r);
    return left + right;
}

void update(int node, int s, int e, int l, int r, ll val) {
    propagate(node, s, e);
    if (e < l || s > r) return;
    if (s >= l && e <= r) {
        lazy[node] += val;
        propagate(node, s, e);
        return;
    }

    int mid = (s + e) / 2;
    update(node * 2, s, mid, l, r, val);
    update(node * 2 + 1, mid + 1, e, l, r, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    init(1, 0, n - 1);
    int m;
    cin >> m;

    while (m--) {
        int op;
        cin >> op;

        if (op == 1) {
            int i, j, k;
            cin >> i >> j >> k;
            i--; j--;

            update(1, 0, n - 1, i, j, k);
        } else {
            int x;
            cin >> x;
            x--;

            cout << query(1, 0, n - 1, x, x) << '\n';
        }
    }
}
