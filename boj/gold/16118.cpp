#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 987654321

using namespace std;

struct Node {
    int end;
    int cost;
    int turn;
};

struct cmp {
    bool operator()(Node a, Node b) {
        return a.cost > b.cost;
    }
};

int n, m;
vector<Node> v[4001];

int dijkstra(int d) {
    priority_queue<Node, vector<Node>, cmp> pq;
    vector<int> distFox;
    distFox.assign(n + 1, INF);
    distFox[1] = 0;
    pq.push({ 1, distFox[1], 0 });

    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();
        int cur = node.end;
        int cost = node.cost;
        int turn = node.turn;

        if (distFox[cur] < cost)
            continue;

        for (int i = 0; i < v[cur].size(); i++) {
            node = v[cur][i];
            int next = node.end;
            int nextCost = cost + node.cost * 2;
            int nextTurn = turn + 1;

            if (distFox[next] > nextCost) {
                distFox[next] = nextCost;
                pq.push({ next, nextCost, nextTurn });
            }
        }
    }

    vector<int> distWolf[2];
    distWolf[0].assign(n + 1, INF);
    distWolf[1].assign(n + 1, INF);
    distWolf[0][1] = 0;
    pq.push({ 1, distWolf[0][1], 0 });

    while (!pq.empty()) {
        Node node = pq.top();
        int cur = node.end;
        int cost = node.cost;
        int turn = node.turn;
        pq.pop();

        if (distWolf[turn % 2][cur] < cost)
            continue;

        for (int i = 0; i < v[cur].size(); i++) {
            node = v[cur][i];
            int next = node.end;
            int nextCost = node.cost;
            int nextTurn = turn + 1;

            if (turn % 2 == 0) {
                nextCost = cost + nextCost;

                if (distWolf[1][next] > nextCost) {
                    distWolf[1][next] = nextCost;
                    pq.push({ next, nextCost, nextTurn });
                }
            } else {
                nextCost = cost + nextCost * 4;

                if (distWolf[0][next] > nextCost) {
                    distWolf[0][next] = nextCost;
                    pq.push({ next, nextCost, nextTurn });
                }
            }
        }
    }

    int ans = 0;
    for (int i = 2; i <= n; i++)
        if (distFox[i] < min(distWolf[0][i], distWolf[1][i]))
            ans++;

    return ans;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int start, end, cost;
        cin >> start >> end >> cost;
        v[start].push_back({ end, cost, 0 });
        v[end].push_back({ start, cost, 0 });
    }

    int ans = dijkstra(n);
    cout << ans;
}
