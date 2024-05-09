#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

vector<pii> graph[501];
int dist[501];
vector<int> rev[501];
bool visited[501];

void dijkstra(int x) {
    dist[x] = 0;
    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.push({0, x});

    while (!pq.empty()) {
        auto [cost, cur] = pq.top();
        pq.pop();

        if (dist[cur] < cost) continue;

        for (int i = 0; i < graph[cur].size(); i++) {
            if (graph[cur][i].second == -1) continue;

            int nxt = graph[cur][i].first;
            int nCost = graph[cur][i].second;

            if (dist[cur] + nCost < dist[nxt]) {
                dist[nxt] = dist[cur] + nCost;
                rev[nxt].clear();
                rev[nxt].push_back(cur);
                pq.push({dist[nxt], nxt});
            } else if (dist[cur] + nCost == dist[nxt])
                rev[nxt].push_back(cur);
        }
    }
}

void bfs(int x) {
    queue<int> q;
    q.push(x);

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        if (visited[x]) continue;

        visited[x] = true;
        for (int i = 0; i < rev[x].size(); i++) {
            int nxt = rev[x][i];

            for (int j = 0; j < graph[nxt].size(); j++)
                if (graph[nxt][j].first == x)
                    graph[nxt][j].second = -1;
            q.push(nxt);
        }
    }
}

void reset() {
    fill(graph, graph + 501, vector<pii>());
    fill(rev, rev + 501, vector<int>());
    memset(dist, 127, sizeof(dist));
    fill(visited, visited + 501, false);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;

        reset();
        int s, e;
        cin >> s >> e;
        while (m--) {
            int u, v, e;
            cin >> u >> v >> e;
            graph[u].push_back({v, e});
        }

        const int INF = dist[0];
        dijkstra(s);
        bfs(e);

        memset(dist, 127, sizeof(dist));

        dijkstra(s);

        if (dist[e] == INF)
            cout << "-1\n";
        else
            cout << dist[e] << '\n';
    }
}
