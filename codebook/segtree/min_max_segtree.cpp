using ll = long long;
#define LEN 1000001

ll a[LEN];
pair<ll, ll> tree[4 * LEN];

void init(int node, int s, int e) {
    if (s == e) {
        tree[node] = { a[s], a[s] };
        return;
    }

    int mid = (s + e) / 2;
    init(2 * node, s, mid);
    init(2 * node + 1, mid + 1, e);

    ll min_val = min(tree[2 * node].first, tree[2 * node + 1].first);
    ll max_val = max(tree[2 * node].second, tree[2 * node + 1].second);
    tree[node] = {min_val, max_val};
}

pair<ll, ll> query(int node, int s, int e, int l, int r) {
    if (e < l || s > r) return { LLONG_MAX, LLONG_MIN };
    if (s >= l && e <= r) return tree[node];

    int mid = (s + e) / 2;
    pair<ll, ll> left = query(node * 2, s, mid, l, r);
    pair<ll, ll> right = query(node * 2 + 1, mid + 1, e, l, r);

    ll min_val = min(left.first, right.first);
    ll max_val = max(left.second, right.second);
    return { min_val, max_val };
}

void update(int node, int s, int e, int idx, ll val) {
    if (idx < s || idx > e) return;
    if (s == e) {
        a[idx] = val;
        tree[node] = { val, val };
        return;
    }

    int mid = (s + e) / 2;
    update(node * 2, s, mid, idx, val);
    update(node * 2 + 1, mid + 1, e, idx, val);

    ll min_val = min(tree[node * 2].first, tree[node * 2 + 1].first);
    ll max_val = max(tree[node * 2].second, tree[node * 2 + 1].second);
    tree[node] = { min_val, max_val };
}