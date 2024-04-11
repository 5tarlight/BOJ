#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int p[100001];
long long dist[100001];

int find(int node) {
    if (p[node] == node) return node;

    int parent = find(p[node]);
    dist[node] += dist[p[node]];
    return p[node] = parent;
}

void merge(int a, int b, int w) {
    int pa = find(a);
    int pb = find(b);

    if (pa == pb) return;

    p[pa] = pb;
    dist[pa] = dist[b] - dist[a] + w;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        for (int i = 1; i <= n; i++) {
            p[i] = i;
            dist[i] = 0;
        }

        while (m--) {
            char op;
            cin >> op;

            if (op == '!') {
                int a, b, w;
                cin >> a >> b >> w;
                merge(a, b, w);
            } else {
                int a, b;
                cin >> a >> b;
                if (find(a) == find(b)) {
                    cout << dist[a] - dist[b] << '\n';
                } else {
                    cout << "UNKNOWN\n";
                }
            }
        }
    }
}
