#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define HEIGHT 20
int n;
int depth[40001];
int parent[40001][HEIGHT];
int dist[40001][HEIGHT];
vector<pair<int, int>> adj[40001];

void find(int p, int x, int dep, int cost) {
    depth[x] = dep;
    parent[x][0] = p;
    dist[x][0] = cost;

    for (int i = 0; i < adj[x].size(); i++)
        if (adj[x][i].first != p)
            find(x, adj[x][i].first, dep + 1, adj[x][i].second);
}

int getDist(int a, int b) {
    int sum = 0;
    if (depth[a] != depth[b]) {
        if (depth[a] > depth[b]) swap(a, b);

        int diff = depth[b] - depth[a];
        for (int i = 0; diff; i++) {
            if (diff & 1) {
                sum += dist[b][i];
                b = parent[b][i];
            }
            diff >>= 1;
        }
    }

    if (a == b) return sum;

    for (int i = HEIGHT - 1; i >= 0; i--) {
        if (parent[a][i] != parent[b][i]) {
            sum += dist[a][i] + dist[b][i];
            a = parent[a][i];
            b = parent[b][i];
        }
    }

    return sum + dist[a][0] + dist[b][0];
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    find(0, 1, 0, 0);

    for (int i = 1; i < HEIGHT; i++) {
        for (int j = 1; j <= n; j++) {
            parent[j][i] = parent[parent[j][i - 1]][i - 1];
            dist[j][i] = dist[j][i - 1] + dist[parent[j][i - 1]][i - 1];
        }
    }

    int m;
    cin >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        cout << getDist(a, b) << '\n';
    }
}
