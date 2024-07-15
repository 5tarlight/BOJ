#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, D;
    cin >> N >> D;

    vector<vector<pair<int, int>>> graph(D + 1);

    for (int i = 0; i < N; ++i) {
        int start, end, length;
        cin >> start >> end >> length;
        if (end <= D) {
            graph[start].push_back({end, length});
        }
    }

    for (int i = 0; i < D; ++i) {
        graph[i].push_back({i + 1, 1});
    }

    vector<int> dist(D + 1, 1e9);
    dist[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        int cost = pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if (cost > dist[current]) continue;

        for (const auto& neighbor : graph[current]) {
            int next = neighbor.first;
            int nextCost = cost + neighbor.second;

            if (nextCost < dist[next]) {
                dist[next] = nextCost;
                pq.push({nextCost, next});
            }
        }
    }

    cout << dist[D];
    return 0;
}
