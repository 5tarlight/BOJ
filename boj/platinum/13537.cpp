#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

constexpr int MAXN = 100000;

int n, q;
vector<int> nums;
vector<vector<int>> seg;

void build(int node, int l, int r) {
    if (l == r) {
        seg[node] = {nums[l]};
        return;
    }

    int mid = (l + r) >> 1;
    build(node << 1, l, mid);
    build(node << 1 | 1, mid + 1, r);

    auto &left = seg[node << 1];
    auto &right = seg[node << 1 | 1];

    seg[node].resize(left.size() + right.size());
    merge(left.begin(), left.end(), right.begin(), right.end(), seg[node].begin());
}

int query(int node, int l, int r, int ql, int qr, int k) {
    if (qr < l || r < ql) return 0;

    if (ql <= l && r <= qr) {
        auto it = upper_bound(seg[node].begin(), seg[node].end(), k);
        return seg[node].end() - it;
    }

    int mid = (l + r) >> 1;
    return query(node << 1, l, mid, ql, qr, k)
         + query(node << 1 | 1, mid + 1, r, ql, qr, k);
}

int main() {
    fio();

    cin >> n;
    nums.resize(n);
    for (auto &x : nums) cin >> x;

    seg.assign(4 * n, {});
    build(1, 0, n - 1);

    cin >> q;
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << query(1, 0, n - 1, l - 1, r - 1, k) << '\n';
    }
}