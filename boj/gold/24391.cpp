#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int parents[100001];

int find(int x) {
    if (parents[x] == x) return x;
    return parents[x] = find(parents[x]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        parents[b] = a;
    }
}

int main() {
    fio();

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        parents[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        unite(a, b);
    }

    int ans = 0;
    int prev = -1;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (prev == -1) {
            prev = x;
        } else {
            if (find(prev) != find(x)) {
                ans++;
            }
            prev = x;
        }
    }

    cout << ans;
}
