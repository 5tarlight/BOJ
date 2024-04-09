#include <iostream>
#include <algorithm>

using namespace std;

long long tree[4000004];
int n, m;

long long sum(int s, int e, int node, int l, int r) {
    if (l > e || r < s) return 0;
    if (l <= s && e <= r) return tree[node];

    int mid = (s + e) / 2;
    return sum(s, mid, node * 2, l, r) + sum(mid + 1, e, node * 2 + 1, l, r);
}

void update(int s, int e, int node, int idx, long long diff) {
    if (idx < s || idx > e) return;

    tree[node] += diff;
    if (s == e) return;

    int mid = (s + e) / 2;
    update(s, mid, node * 2, idx, diff);
    update(mid + 1, e, node * 2 + 1, idx, diff);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 0) {
            if (b > c) swap(b, c);
            cout << sum(1, n, 1, b, c) << '\n';
        } else
            update(1, n, 1, b, c - sum(1, n, 1, b, b));
    }
}
