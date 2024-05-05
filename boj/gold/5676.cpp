#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int tree[400004];
int arr[100001];

int normalize(ll v) {
    if (v > 0) return 1;
    else if (v < 0) return -1;
    else return 0;
}

ll init(int s, int e, int node) {
    if (s == e)
        return tree[node] = normalize(arr[s]);

    int mid = (s + e) / 2;
    return tree[node] = init(s, mid, node * 2) * init(mid + 1, e, node * 2 + 1);
}

ll sum(int s, int e, int node, int l, int r) {
    if (l > e || r < s)
        return 1;
    if (l <= s && e <= r)
        return tree[node];

    int mid = (s + e) / 2;
    return sum(s, mid, node * 2, l, r) * sum(mid + 1, e, node * 2 + 1, l, r);
}

int update(int s, int e, int node, int idx, ll val) {
    if (idx < s || idx > e)
        return tree[node];

    if (s == e) {
        arr[idx] = val;
        return tree[node] = normalize(val);
    }

    int mid = (s + e) / 2;
    int left = update(s, mid, node * 2, idx, val);
    int right = update(mid + 1, e, node * 2 + 1, idx, val);
    return tree[node] = left * right;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, k;
    while (cin >> n >> k) {
        for (int i = 1; i <= n; i++)
            cin >> arr[i];

        init(1, n, 1);

        while (k--) {
            char op;
            int a, b;
            cin >> op >> a >> b;

            if (op == 'C')
                update(1, n, 1, a, b);
            else {
                ll res = sum(1, n, 1, a, b);

                if (res > 0) cout << '+';
                else if (res < 0) cout << '-';
                else cout << '0';
            }
        }

        cout << '\n';
    }
}
