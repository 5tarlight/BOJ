#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long el;
typedef vector<el> seg;

void init(seg &a, seg &tree, int node, int start, int end) {
    if (start == end) {
        tree[node] = a[start];
    } else {
        init(a, tree, node * 2, start, (start + end) / 2);
        init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}

void update(seg &a, seg &tree, int node, int start, int end, int index, el val) {
    if (index < start || index > end)
        return;
    if (start == end) {
        a[index] = val;
        tree[node] = val;
        return;
    }
    update(a, tree,node * 2, start, (start + end) / 2, index, val);
    update(a, tree,node * 2 + 1, (start + end) / 2 + 1, end, index, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void updateLazy(seg &tree, seg &lazy, int node, int start, int end) {
    if (lazy[node] != 0) {
        tree[node] += (end - start + 1) * lazy[node];
        if (start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void updateRange(seg &tree, seg &lazy, int node, int start, int end, int left, int right, el diff) {
    updateLazy(tree, lazy, node, start, end);
    if (left > end || right < start)
        return;
    if (left <= start && end <= right) {
        tree[node] += (end - start + 1) * diff;
        if (start != end) {
            lazy[node * 2] += diff;
            lazy[node * 2 + 1] += diff;
        }
        return;
    }

    updateRange(tree, lazy, node * 2, start, (start + end) / 2, left, right, diff);
    updateRange(tree, lazy, node * 2 + 1, (start + end) / 2 + 1, end, left, right, diff);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

el query(seg &tree, seg &lazy, int node, int start, int end, int left, int right) {
    updateLazy(tree, lazy, node, start, end);
    if (left > end || right < start)
        return 0;
    if (left <= start && end <= right)
        return tree[node];

    el lmin = query(tree, lazy, node * 2, start, (start + end) / 2, left, right);
    el rmin = query(tree, lazy, node * 2 + 1, (start + end) / 2 + 1, end, left, right);

    return rmin + lmin;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    seg a(n);

    int h = (int)ceil(log2(n));
    int treeSize = 1 << (h + 1);
    seg tree(treeSize);
    seg lazy(treeSize);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    init(a, tree, 1, 0, n - 1);

    int m;
    cin >> m;
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int left, right;
            el diff;
            cin >> left >> right >> diff;

            updateRange(tree, lazy, 1, 0, n - 1, left - 1, right - 1, diff);
        } else {
            int x;
            cout << query(tree, lazy, 1, 0, n - 1, x - 1, x - 1) << '\n';
        }
    }
}
