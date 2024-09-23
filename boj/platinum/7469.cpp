#include "bits/stdc++.h"

using namespace std;

constexpr int MAX = 100000;

int n, m;
int a[MAX];
vector<int> tree[4 * MAX];

void init(int s, int e, int node) {
    if (s == e) {
        tree[node].push_back(a[s]);
        return;
    }

    int mid = (s + e) / 2;

    init(s, mid, 2 * node);
    init(mid + 1, e, 2 * node + 1);

    auto& left = tree[2 * node];
    auto& right = tree[2 * node + 1];
    auto l = left.begin();
    auto r = right.begin();

    while (l != left.end() || r != right.end()) {
        if (l == left.end()) {
            tree[node].push_back(*r++);
        } else if (r == right.end()) {
            tree[node].push_back(*l++);
        } else {
            if (*l < *r)
                tree[node].push_back(*l++);
            else
                tree[node].push_back(*r++);
        }
    }
}

int query(int s, int e, int l, int r, int num, int node) {
    if (e < l || r < s)
        return 0;
    if (l <= s && e <= r)
        return lower_bound(tree[node].begin(), tree[node].end(), num) - tree[node].begin();
    return query(s, (s + e) / 2, l, r, num, 2 * node)
            + query((s + e) / 2 + 1, e, l, r, num, 2 * node + 1);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    init(0, n - 1, 1);

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;

        int l = -1e9;
        int r = 1e9;
        int ans = -1e9;

        while (l <= r) {
            int mid = (l + r) / 2;
            int q = query(0, n - 1, a - 1, b - 1, mid, 1);

            if (q < c) {
                ans = max(ans, mid);
                l = mid + 1;
            } else
                r = mid - 1;
        }

        cout << ans << '\n';
    }
}
