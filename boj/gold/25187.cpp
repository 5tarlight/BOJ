#include <iostream>

using namespace std;

int parents[200'001];
int ans[200'001];

int find(int x) {
    if (parents[x] == x) return x;
    return parents[x] = find(parents[x]);
}

void unite(int a, int b) {
    int pa = find(a);
    int pb = find(b);

    if (pa != pb) {
        parents[pa] = pb;
        ans[pb] += ans[pa];
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        cin >> ans[i];
        if (ans[i] == 0)
            ans[i] = -1;
        parents[i] = i;
    }

    while (m--) {
        int a, b;
        cin >> a >> b;
        unite(a, b);
    }

    while (q--) {
        int x;
        cin >> x;
        cout << (int)(ans[find(x)] > 0) << '\n';
    }
}
