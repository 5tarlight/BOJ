#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a, x;
int max_r;

bool dfs(int idx, int rem) {
    if (idx == n - 1) {
        x[idx] = rem;
        int g = 0;
        for (int i = 0; i < n; i++) {
            int bi = a[i] + x[i];
            g = (i == 0 ? bi : gcd(g, bi));
        }
        return g == 1;
    } else {
        for (int v = 0; v <= rem; v++) {
            x[idx] = v;
            if (dfs(idx + 1, rem - v)) return true;
        }
        return false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int G = a[0];
    for (int i = 1; i < n; i++) {
        G = gcd(G, a[i]);
    }
    if (G == 1) {
        cout << 0;
        return 0;
    }

    if (n >= 8) {
        cout << 1;
        return 0;
    }

    if (n == 2) max_r = 5;
    else if (n == 3) max_r = 3;
    else max_r = 2;

    x.assign(n, 0);
    for (int r = 1; r <= max_r; r++) {
        if (dfs(0, r)) {
            cout << r;
            return 0;
        }
    }

    return 0;
}
