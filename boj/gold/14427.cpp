#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 100000

int a[MAX + 1];
int tree[MAX * 4 + 1];

int minIdx(int i, int j) {
    if (a[i] == a[j])
        return min(i, j);
    return a[i] < a[j] ? i : j;
}

int init(int s, int e, int node) {
    if (s == e)
        return tree[node] = s;

    int mid = (s + e) / 2;
    return tree[node] = minIdx(init(s, mid, node * 2), init(mid + 1, e, node * 2 + 1));
}

int update(int s, int e, int node, int idx) {
    if (idx < s || idx > e || s == e)
        return tree[node];

    int mid = (s + e) / 2;
    return tree[node] = minIdx(update(s, mid, node * 2, idx), update(mid + 1, e, node * 2 + 1, idx));
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    init(0, n - 1, 1);

    int m;
    cin >> m;
    while (m--) {
        int q;
        cin >> q;

        if (q == 1) {
            int idx, v;
            cin >> idx >> v;
            idx--;
            a[idx] = v;
            update(0, n - 1, 1, idx);
        } else {
            cout << tree[1] + 1 << '\n';
        }
    }
}
