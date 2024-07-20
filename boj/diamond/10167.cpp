#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

struct Point {
    ll x, y, w;
    bool operator<(const Point &p) const {
        if (x != p.x) return x < p.x;
        else return y < p.y;
    }
};

struct Node {
    ll sum, l, r, lr;
};

int bias = 4096; // 1 0000 0000 0000
Node tree[10000];

void init() {
    for (int i = 0; i < 10000; i++)
        tree[i].sum = tree[i].l = tree[i].r = tree[i].lr = 0;
}

Node find(Node &a, Node &b) {
    Node ans{};
    ans.sum = a.sum + b.sum;
    ans.l = max(a.l, a.sum + b.l);
    ans.r = max(b.r, a.r + b.sum);
    ans.lr = max({ a.r + b.l, a.lr, b.lr, ans.sum });

    return ans;
}

void update(long long x, long long v) {
    x |= bias;
    tree[x].sum = tree[x].l = tree[x].r = tree[x].lr += v;

    while (x >>= 1)
        tree[x] = find(tree[2 * x], tree[2 * x + 1]);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    Point a[n];
    vector<ll> x, y;
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y >> a[i].w;
        x.push_back(a[i].x);
        y.push_back(a[i].y);
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    y.erase(unique(y.begin(), y.end()), y.end());

    for (auto &i : a) {
        i.y = lower_bound(x.begin(), x.end(), i.x) - x.begin();
        i.x = lower_bound(y.begin(), y.end(), i.y) - y.begin();
    }
    sort(a, a + n);

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        if (i && a[i - 1].x == a[i].x)
            continue;
        init();

        for (int j = i; j < n; j++) {
            update(a[j].y, a[j].w);

            if (j == n - 1 || a[j].x != a[j + 1].x)
                ans = max(ans, tree[1].lr);
        }
    }

    cout << ans;
}
