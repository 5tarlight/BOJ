#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

constexpr int MOD = 1e9 + 7;
constexpr int N = 100001;

int tree[12][N];

void update(int u, int x, int v) {
    for (; x < N; x += x & -x)
        if (tree[u][x] += v; tree[u][x] >= MOD)
            tree[u][x] -= MOD;
}

int query(int u, int x, int ans = 0) {
    for (; x; x -= x & -x)
        if (ans += tree[u][x]; ans >= MOD)
            ans -= MOD;
    return ans;
}

int main() {
    fio();

    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        update(1, x, 1);
        for (int j = 2; j < 12; j++) {
            int val = query(j - 1, x - 1);
            update(j, x, val);
        }
    }

    cout << query(11, 1e5);
}
