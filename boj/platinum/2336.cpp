#include "bits/stdc++.h"

using namespace std;

struct S {
    int a, b, c;
};

bool cmp(S a, S b) {
    return a.a < b.a;
}

constexpr int MAX = 500001;
S a[MAX];
int tree[4 * MAX];

int update(int node, int s, int e, int idx, int v) {
    if (idx < s || e < idx) return tree[node];
    if (s == e) return tree[node] = v;

    int mid = (s + e) / 2;
    return tree[node] = min(
        update(2 * node, s, mid, idx, v),
        update(2 * node + 1, mid + 1, e, idx, v)
    );
}

int query(int node, int s, int e, int l, int r) {
    if (r < s || e < l) return 1e9;
    if (l <= s && e <= r) return tree[node];

    int mid = (s + e) / 2;
    return min(
        query(2 * node, s, mid, l, r),
        query(2 * node + 1, mid + 1, e, l, r)
    );
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        a[t].a = i;
    }

    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        a[t].b = i;
    }

    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        a[t].c = i;
    }

    sort(a + 1, a + n + 1, cmp);

    for (int i = 1; i <= n; i++)
        update(1, 1, n, i, 1e9);

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        if (query(1, 1, n, 1, a[i].b) > a[i].c)
            ans++;
        update(1, 1, n, a[i].b, a[i].c);
    }

    cout << ans;
}
