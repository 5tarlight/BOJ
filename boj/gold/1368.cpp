#include "bits/stdc++.h"

using namespace std;

int n;
int p[301];

int find(int x) {
    if (p[x] == x) return x;
    return p[x] = find(p[x]);
}

void uni(int a, int b) {
    a = find(a); b = find(b);
    p[a] = b;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) p[i] = i;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        pq.push({ x, { i, 0 }});
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x; cin >> x;
            pq.push({ x, { i, j }});
        }
    }

    int ans = 0;
    while (!pq.empty()) {
        auto [cost, p] = pq.top(); pq.pop();
        auto [a, b] = p;

        if (find(a) == find(b)) continue;

        ans += cost;
        uni(a, b);
    }

    cout << ans;
}
