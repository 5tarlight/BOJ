#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

int n;
int a[1000001];
vector<int> tree;

int query(int node, int l, int r, int cnt) {
    if (l == r) return l;

    int mid = (l + r) / 2;
    if (tree[node * 2] >= cnt) return query(node * 2, l, mid, cnt);
    else return query(node * 2 + 1, mid + 1, r, cnt - tree[node * 2]);
}

void update(int node, int l, int r, int idx, int diff) {
    if (idx < l || idx > r) return;
    tree[node] += diff;

    if (l != r) {
        int mid = (l + r) / 2;
        update(node * 2, l, mid, idx, diff);
        update(node * 2 + 1, mid + 1, r, idx, diff);
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    int height = (int)ceil(log2(1000000));
    tree.resize(1 << (height + 1));

    while (n--) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int idx;
            cin >> idx;
            int ans = query(1, 1, 1000000, idx);
            cout << ans << '\n';
            a[ans]--;
            update(1, 1, 1000000, ans, -1);
        } else {
            int idx, v;
            cin >> idx >> v;
            a[idx] += v;
            update(1, 1, 1000000, idx, v);
        }
    }
}
