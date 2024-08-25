#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a[1000001];
int s[1000001];
int e[1000001];
vector<int> v, root(1000001);
int n, q;

struct Node {
    int l, r;
    int cnt;
};

vector<Node> tree(50000000);
int nodeCnt;

void init() {
    nodeCnt = 2 * n;
    for (int i = 1; i < n; i++) {
        tree[i].l = i * 2;
        tree[i].r = i * 2 + 1;
    }
}

void update(int node, int st, int en, int idx, int val) {
    tree[node].cnt += val;

    if (st == en) return;

    int mid = (st + en) / 2;
    int n1 = tree[node].l;
    int n2 = tree[node].r;

    if (idx <= mid) {
        tree[node].l = nodeCnt;
        tree[nodeCnt++] = tree[n1];
        update(tree[node].l, st, mid, idx, val);
    } else {
        tree[node].r = nodeCnt;
        tree[nodeCnt++] = tree[n2];
        update(tree[node].r, mid + 1, en, idx, val);
    }
}

int query(int node, int st, int en, int l, int r) {
    if (l <= st && en <= r)
        return tree[node].cnt;
    if (en < l || st > r)
        return 0;

    int mid = (st + en) / 2;
    int n1 = tree[node].l;
    int n2 = tree[node].r;

    return query(n1, st, mid, l, r) + query(n2, mid + 1, en, l, r);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();

    vector<int> prevIdx(v.size(), 0);
    vector<int> prev(n + 1, -1);

    for (int i = 1; i <= n; i++) {
        if (prevIdx[a[i]] != 0)
            prev[i] = prevIdx[a[i]];
        prevIdx[a[i]] = i;
    }

    init();

    root[0] = 1;
    int cur = root[0];
    for (int i = 1; i <= n; i++) {
        tree[nodeCnt] = tree[cur];
        cur = nodeCnt++;
        update(cur, 1, n, i, 1);

        if (prev[i] != -1) {
            tree[nodeCnt] = tree[cur];
            cur = nodeCnt++;
            update(cur, 1, n, prev[i], -1);
        }
        root[i] = cur;
    }

    cin >> q;
    int ans = 0;
    while (q--) {
        int x, r;
        cin >> x >> r;
        int l = x + ans;

        ans = query(root[r], 1, n, l, r);
        cout << ans << '\n';
    }
}
