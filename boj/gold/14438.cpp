#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void init(vector<long long> &a, vector<long long> &tree, int node, int start, int end) {
    if (start == end) {
        tree[node] = a[start];
    } else {
        init(a, tree, node * 2, start, (start + end) / 2);
        init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }
}

long long query(vector<long long> &tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start)
        return -1;
    if (left <= start && end <= right)
        return tree[node];

    long long lmin = query(tree, node * 2, start, (start + end) / 2, left, right);
    long long rmin = query(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);

    if (lmin == -1)
        return rmin;
    else if (rmin == -1)
        return lmin;
    else
        return min(rmin, lmin);
}

void update(vector<long long> &a, vector<long long> &tree, int node, int start, int end, int index, long long val) {
    if (index < start || index > end)
        return;
    if (start == end) {
        a[index] = val;
        tree[node] = val;
        return;
    }
    update(a, tree,node * 2, start, (start + end) / 2, index, val);
    update(a, tree,node * 2 + 1, (start + end) / 2 + 1, end, index, val);
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n);
    int h = (int)ceil(log2(n));
    int treeSize = 1 << (h + 1);
    vector<long long> tree(treeSize);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    init(a, tree, 1, 0, n - 1);

    int m;
    cin >> m;
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int i;
            long long v;
            cin >> i >> v;

            update(a, tree, 1, 0, n - 1, i - 1, v);
        } else {
            int left, right;
            cin >> left >> right;
            cout << query(tree, 1, 0, n - 1, left - 1, right - 1) << '\n';
        }
    }
}
