#include <iostream>
#include <queue>

using namespace std;

int n, m;
int parents[100001];

int find(int x) {
    if (x == parents[x]) return x;
    else return parents[x] = find(parents[x]);
}

void unite(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    if (pa == pb) return;

    parents[pa] = pb;
}

struct Edge {
    int from;
    int to;
    int t;
};

struct Cmp {
    bool operator()(const Edge &a, const Edge &b) const {
        return a.t > b.t;
    }
};

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    priority_queue<Edge, vector<Edge>, Cmp> pq;
    while (m--) {
        int u, v, t;
        cin >> u >> v >> t;
        pq.push({ u, v, t });
    }

    for (int i = 1; i <= n; i++)
        parents[i] = i;

    int prev = 0;
    while (!pq.empty()) {
        auto [from, to, t] = pq.top();
        pq.pop();

        if (t != prev + 1) {
            cout << prev + 1;
            return 0;
        }

        if (find(from) == find(to))
            continue;

        prev = t;
        unite(from, to);
    }

    cout << prev + 1;
}
