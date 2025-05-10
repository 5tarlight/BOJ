#include <bits/stdc++.h>
using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

struct Edge { int u, v, w; };

int parent[1001];
int n, m;
vector<Edge> edges;

int find(int x) {
    return parent[x] == x ? x : parent[x] = find(parent[x]);
}

bool unite(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return false;
    parent[a] = b;
    return true;
}

long long krsk(bool asc) {
    if (asc)
        sort(edges.begin(), edges.end(), [](Edge a, Edge b) { return a.w < b.w; });
    else
        sort(edges.begin(), edges.end(), [](Edge a, Edge b) { return a.w > b.w; });

    for (int i = 0; i <= n; i++) parent[i] = i;

    int used = 0, cnt = 0;
    for (auto &e : edges) {
        if (unite(e.u, e.v)) {
            used++;
            if (e.w == 1) cnt++;
            if (used == n) break;
        }
    }
    return cnt;
}

int main() {
    fio();
    cin >> n >> m;
    edges.resize(m + 1);
    for (int i = 0; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = {a, b, c == 0 ? 1 : 0};
    }

    long long lo = krsk(true), hi = krsk(false);
    cout << hi * hi - lo * lo;
}