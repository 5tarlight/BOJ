#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll tree[4000004];
ll arr[1000001];

ll init(int s, int e, int node) {
    if (s == e)
        return tree[node] = arr[s];

    int mid = (s + e) / 2;
    return tree[node] = init(s, mid, node * 2) + init(mid + 1, e, node * 2 + 1);
}

ll sum(int s, int e, int node, int l, int r) {
    if (l > e || r < s)
        return 0;
    if (l <= s && e <= r)
        return tree[node];

    int mid = (s + e) / 2;
    return sum(s, mid, node * 2, l, r) + sum(mid + 1, e, node * 2 + 1, l, r);
}

void update(int s, int e, int node, int idx, ll diff) {
    if (idx < s || idx > e)
        return;

    tree[node] += diff;
    if (s == e)
        return;

    int mid = (s + e) / 2;
    update(s, mid, node * 2, idx, diff);
    update(mid + 1, e, node * 2 + 1, idx, diff);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    init(1, n, 1);
    while (q--) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;

        if (x > y)
            swap(x, y);

        cout << sum(1, n, 1, x, y) << '\n';

        ll diff = b - arr[a];
        update(1, n, 1, a, diff);
        arr[a] = b;
    }
}
