#include <iostream>

using namespace std;

#define LEN 1000001
typedef long long ll;

ll a[LEN];
ll tree[4 * LEN];

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

ll query(int node, int s, int e, int l, int r) {
    if (e < l || s > r) return 0;
    if (s >= l && e <= r) return tree[node];

    int mid = (s + e) / 2;
    ll left = query(node * 2, s, mid, l, r);
    ll right = query(node * 2 + 1, mid + 1, e, l, r);
    return left + right;
}

void update(int node, int s, int e, int idx, ll val) {
    if (idx < s || idx > e) return;
    if (s == e) {
        tree[node] = val;
        return;
    }

    int mid = (s + e) / 2;
    update(node * 2, s, mid, idx, val);
    update(node * 2 + 1, mid + 1, e, idx, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;
    m += k;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    init(1, 0, n - 1);

    while (m--) {
        ll op, x, y;
        cin >> op >> x >> y;

        if (op == 1)
            update(1, 0, n - 1, x - 1, y);
        else
            cout << query(1, 0, n - 1, x - 1, y - 1) << '\n';
    }
}
