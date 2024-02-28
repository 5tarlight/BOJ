#include <iostream>
#include <algorithm>

using namespace std;

int parents[1001];

int find(int x) {
    if (parents[x] == x)
        return x;
    else
        return parents[x] = find(parents[x]);
}

void uni(int x, int y) {
    parents[find(x)] = find(y);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    pair<int, pair<int, int>> d[m];
    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        d[i] = { c, { a, b }};
    }
    for (int i = 1; i <= n; i++)
        parents[i] = i;

    sort(d, d + m);

    int ans = 0;
    for (auto &p : d) {
        c = p.first;
        a = p.second.first;
        b = p.second.second;

        if (find(a) != find(b)) {
            ans += c;
            uni(a, b);
        }
    }

    cout << ans;
}
