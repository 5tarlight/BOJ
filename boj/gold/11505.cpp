#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define DIV 1'000'000'007

typedef long long ll;
typedef vector<ll> vec;

vec a, tree;

void init(int node, int start, int end) {
    if (start == end)
        tree[node] = a[start];
    else {
        init(node * 2, start, (start + end) / 2);
        init(node * 2 + 1, (start + end) / 2 + 1, end);
        tree[node] = tree[node * 2] * tree[node * 2 + 1] % DIV;
    }
}

ll query(int node, int start, int end, int left, int right) {
    if (left > end || right < start)
        return 1;
    else if (left <= start && right >= end)
        return tree[node];

    ll lsum = query(node * 2, start, (start + end) / 2, left, right);
    ll rsum = query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);

    return lsum * rsum % DIV;
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
    tree[node] = tree[node * 2] * tree[node * 2 + 1] % DIV;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    int s = 1 << ((int)ceil(log2(n)) + 1);
    a = vec(n);
    tree = vec(s);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    m += k;

    init(1, 0, n-1);
    while (m--) {
        int what;
        cin >> what;
        if (what == 1) {
            int index;
            long long val;
            cin >> index >> val;
            update(1, 0, n-1, index-1, val);
        } else if (what == 2) {
            int left, right;
            cin >> left >> right;
            cout << query(1, 0, n-1, left-1, right-1) << '\n';
        }
    }
}
