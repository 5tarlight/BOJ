#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<ll> vec;

vec a, tree;

void init(int node, int start, int end) {
    if (start == end)
        tree[node] = a[start];
    else {
        init(node * 2, start, (start + end) / 2);
        init(node * 2 + 1, (start + end) / 2 + 1, end);
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }
}

ll query(int node, int start, int end, int left, int right) {
    if (left > end || right < start)
        return -1;
    else if (left <= start && right >= end)
        return tree[node];

    ll lsum = query(node * 2, start, (start + end) / 2, left, right);
    ll rsum = query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);

    if (lsum == -1)
        return rsum;
    else if (rsum == -1)
        return lsum;
    else
        return min(lsum, rsum);
}

void update(int node, int start, int end, int index, ll val) {
    if (index < start || end < index)
        return;

    if (start == end) {
        a[index] = val;
        tree[node] = val;
        return;
    }

    update(node * 2, start, (start + end) / 2, index, val);
    update(node * 2 + 1, (start + end) / 2 + 1, end, index, val);
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int s = 1 << ((int)ceil(log2(n)) + 1);
    a = vec(n);
    tree = vec(s);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    init(1, 0, n-1);

    while (m--) {
        int start, end;
        cin >> start >> end;
        cout << query(1, 0, n - 1, start - 1, end - 1) << '\n';
    }
}
