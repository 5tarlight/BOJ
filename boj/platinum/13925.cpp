#include <iostream>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll a[100001];
ll tree[404004];
ll lazy[404004][2];
const ll DIV = 1e9 + 7;

ll init(int node, int s, int e) {
    if (s == e) return tree[node] = a[s];

    int mid = (s + e) / 2;
    return tree[node] = (init(node * 2, s, mid) + init(node * 2 + 1, mid + 1, e)) % DIV;
}

void updateLazy(int node, int s, int e) {
    ll &a = lazy[node][0];
    ll &b = lazy[node][1];

    if (a == 1 && b == 0) return;

    if (s != e) {
        for (int i = node * 2; i <= node * 2 + 1; i++) {
            ll aa = lazy[i][0];
            ll bb = lazy[i][1];
            lazy[i][0] = a * aa % DIV;
            lazy[i][1] = (a * bb + b) % DIV;
        }
    }

    tree[node] = (a * tree[node] + (e - s + 1) * b) % DIV;
    a = 1;
    b = 0;
}

void update(int node, int s, int e, int l, int r, ll mul, ll sum) {
    updateLazy(node, s, e);

    if (r < s || e < l) return;

    if (l <= s && e <= r) {
        lazy[node][0] *= mul;
        lazy[node][0] %= DIV;
        lazy[node][1] *= mul;
        lazy[node][1] %= DIV;
        lazy[node][1] += sum;
        lazy[node][1] %= DIV;
        updateLazy(node, s, e);
        return;;
    }

    int mid = (s + e) / 2;
    update(node * 2, s, mid, l, r, mul, sum);
    update(node * 2 + 1, mid + 1, e, l, r, mul, sum);
    tree[node] = (tree[node * 2] + tree[node * 2 + 1]) % DIV;
}

ll query(int node, int s, int e, int l, int r) {
    updateLazy(node, s, e);

    if (r < s || e < l) return 0;
    if (l <= s && e <= r) return tree[node] % DIV;

    int mid = (s + e) / 2;
    return (query(node * 2, s, mid, l, r) + query(node * 2 + 1, mid + 1, e, l, r)) % DIV;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    init(1, 1, n);

    for (int i = 0; i < 404004; i++) {
        lazy[i][0] = 1;
        lazy[i][1] = 0;
    }

    int m;
    cin >> m;
    while (m--) {
        int op;
        cin >> op;
        ll x, y, v;
        cin >> x >> y;
        if (op != 4) cin >> v;

        if (op == 1)
            update(1, 1, n, x, y, 1, v);
        else if (op == 2)
            update(1, 1, n, x, y, v, 0);
        else if (op == 3)
            update(1, 1, n, x, y, 0, v);
        else
            cout << query(1, 1, n, x, y) << '\n';
    }
}
