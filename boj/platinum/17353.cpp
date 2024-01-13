#include <iostream>

using namespace std;

typedef long long ll;

ll a[100'001];
ll tree[400'001];
ll lazy[400'001];

void updateLazy(int x, int s, int e);
void updateRange(int x, int s, int e, int l, int r, ll v);
ll sum(int x, int s, int e, int l, int r);

ll sum(int x, int s, int e, int l, int r) {
    updateLazy(x, s, e);

    if (s > r || e < l)
        return 0;
    else if (s >= l && e <= r)
        return tree[x];
    else
        return sum(x * 2, s, (s + e) / 2, l, r) + sum(x * 2 + 1, (s + e) / 2 + 1, e, l, r);
}

void updateRange(int x, int s, int e, int l, int r, ll v) {
    updateLazy(x, s, e);
    if (s > r || e < l)
        return;

    if (s >= l && e <= r) {
        tree[x] += (e - s + 1) * v;

        if (s != e) {
            lazy[x * 2] += v;
            lazy[x * 2 + 1] += v;
        }

        return;
    }

    updateRange(x * 2, s, (s + e) / 2, l, r, v);
    updateRange(x * 2 + 1, (s + e) / 2 + 1, e, l, r, v);
    tree[x] = tree[x * 2] + tree[x * 2 + 1];
}

void updateLazy(int x, int s, int e) {
    if (lazy[x] != 0) {
        tree[x] += (e - s + 1) * lazy[x];

        if (s != e) {
            lazy[x * 2] += lazy[x];
            lazy[x * 2 + 1] += lazy[x];
        }

        lazy[x] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        updateRange(1, 1, n, i, i, a[i] - a[i-1]);

    int q;
    cin >> q;
    while (q--) {
        int op;
        cin >> op;

        if (op == 1) {
            int l, r;
            cin >> l >> r;

            updateRange(1, 1, n, l, r, 1);
            updateRange(1, 1, n, r + 1, r + 1, -r + l - 1);
        } else {
            int x;
            cin >> x;
            cout << sum(1, 1, n, 1, x) << '\n';
        }
    }
}
