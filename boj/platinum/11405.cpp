#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

constexpr int MAX = 205;
constexpr int INF = 1e9;
constexpr int SOURCE = 1;
constexpr int SINK = 2;

int cap[MAX][MAX], flow[MAX][MAX], cost[MAX][MAX];
vector<int> adj[MAX];

int mcmf(int source, int sink) {
    int totalCost = 0;

    while (true) {
        bool inQueue[MAX]{};
        int parent[MAX]{};
        int dist[MAX];
        fill(dist, dist + MAX, INF);
        dist[source] = 0;

        queue<int> q;
        q.push(source);
        inQueue[source] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            inQueue[u] = false;

            for (auto v : adj[u]) {
                if (cap[u][v] - flow[u][v] > 0 &&
                    dist[u] + cost[u][v] < dist[v]) {

                    dist[v] = dist[u] + cost[u][v];
                    parent[v] = u;

                    if (!inQueue[v]) {
                        q.push(v);
                        inQueue[v] = true;
                    }
                }
            }
        }

        if (!parent[sink]) break;

        int aug = INF;
        for (int v = sink; v != source; v = parent[v])
            aug = min(aug, cap[parent[v]][v] - flow[parent[v]][v]);

        for (int v = sink; v != source; v = parent[v]) {
            totalCost += aug * cost[parent[v]][v];
            flow[parent[v]][v] += aug;
            flow[v][parent[v]] -= aug;
        }
    }

    return totalCost;
}

int main() {
    fio();

    int N, M;
    cin >> N >> M;

    // sink side
    for (int i = M + 3; i < M + N + 3; i++) {
        adj[i].push_back(SINK);
        adj[SINK].push_back(i);
        cin >> cap[i][SINK];
    }

    // source side
    for (int i = 3; i < M + 3; i++) {
        adj[SOURCE].push_back(i);
        adj[i].push_back(SOURCE);
        cin >> cap[SOURCE][i];
    }

    // bipartite edges
    for (int i = 3; i < M + 3; i++) {
        for (int j = M + 3; j < M + N + 3; j++) {
            adj[i].push_back(j);
            adj[j].push_back(i);
            cap[i][j] = INF;

            cin >> cost[i][j];
            cost[j][i] = -cost[i][j];
        }
    }

    cout << mcmf(SOURCE, SINK);
}