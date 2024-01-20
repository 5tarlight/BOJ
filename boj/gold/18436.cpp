#include <iostream>

using namespace std;

#define MAX 100001

int a[MAX];
int tree[MAX * 4];

int init(int start, int end, int node) {
    if (start == end)
        return tree[node] = a[start] % 2 == 0 ? 0 : 1;

    int mid = (start + end) >> 1;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

void update(int start, int end, int node, int index, int x, int value) {
    if (start > index || index > end)
        return;
    if (x % 2 == 0)
        tree[node]--;
    else
        tree[node]++;
    if (start == end) {
        tree[node] = value;
        return;
    }

    int mid = (start + end) >> 1;
    update(start, mid, node * 2, index, x, value);
    update(mid + 1, end, node * 2 + 1, index, x, value);
}

int query(int start, int end, int node, int left, int right) {
    if (start > right || end < left)
        return 0;
    if (left <= start && end <= right)
        return tree[node];

    int mid = (start + end) >> 1;
    return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    init(1, n, 1);

    cin >> m;
    while (m--) {
        int q;
        cin >> q;
        if (q == 1) {
            int index, x;
            cin >> index >> x;

            if (a[index] % 2 == 0 && x % 2 == 1)
                update(1, n, 1, index, x, 1);
            else if (a[index] % 2 == 1 && x % 2 == 0)
                update(1, n, 1, index, x, 0);
            a[index] = x;
        } else if (q == 2) {
            int left, right;
            cin >> left >> right;
            int num = right - left + 1;
            cout << num - query(1, n, 1, left, right) << '\n';
        } else {
            int left, right;
            cin >> left >> right;
            cout << query(1, n, 1, left, right) << '\n';
        }
    }
}
