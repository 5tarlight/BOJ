using ll = long long;
#define LEN 1000001

ll a[LEN];
pair<ll, ll> tree[4 * LEN];
ll lazy[4 * LEN];

void init(int node, int s, int e) {
    if (s == e) {
        tree[node] = {a[s], a[s]};
        return;
    }

    int mid = (s + e) / 2;
    init(2 * node, s, mid);
    init(2 * node + 1, mid + 1, e);
    tree[node].first = min(tree[2 * node].first, tree[2 * node + 1].first);
    tree[node].second = max(tree[2 * node].second, tree[2 * node + 1].second);
}

void propagate(int node, int s, int e) {
    if (lazy[node] != 0) {
        tree[node].first += lazy[node];
        tree[node].second += lazy[node];
        if (s != e) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

pair<ll, ll> query(int node, int s, int e, int l, int r) {
    propagate(node, s, e);
    if (e < l || s > r) return { LLONG_MAX, LLONG_MIN };
    
    if (s >= l && e <= r) return tree[node];

    int mid = (s + e) / 2;
    pair<ll, ll> left = query(node * 2, s, mid, l, r);
    pair<ll, ll> right = query(node * 2 + 1, mid + 1, e, l, r);
    
    return {min(left.first, right.first), max(left.second, right.second)};
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
    
    tree[node].first = min(tree[node * 2].first, tree[node * 2 + 1].first);
    tree[node].second = max(tree[node * 2].second, tree[node * 2 + 1].second);
}
