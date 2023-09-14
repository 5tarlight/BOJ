#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int bfs(vector<int> *graph, int n) {
    int count = 0;
    queue<int> q;
    bool visited[n + 1];
    memset(visited, false, sizeof(visited));

    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        count++;

        for (int p : graph[x]) {
            if (!visited[p]) {
                visited[p] = true;
                q.push(p);
            }
        }
    }

    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> graph[n + 1];

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    cout << bfs(graph, n) - 1;
}
