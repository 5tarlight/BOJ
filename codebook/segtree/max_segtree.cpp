using ll = long long;
#define LEN 1000001

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
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

ll query(int node, int s, int e, int l, int r) {
    if (e < l || s > r) return 1e9;
    if (s >= l && e <= r) return tree[node];

    int mid = (s + e) / 2;
    ll left = query(node * 2, s, mid, l, r);
    ll right = query(node * 2 + 1, mid + 1, e, l, r);
    return min(left, right);
}

void update(int node, int s, int e, int idx, ll val) {
    if (idx < s || idx > e) return;
    if (s == e) {
        a[idx] = val;
        tree[node] = val;
        return;
    }

    int mid = (s + e) / 2;
    update(node * 2, s, mid, idx, val);
    update(node * 2 + 1, mid + 1, e, idx, val);
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}
