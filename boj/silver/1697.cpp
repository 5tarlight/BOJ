#include <iostream>
#include <queue>
#include <cstring>

#define SIZE 100'001

using namespace std;

int graph[SIZE];
bool visited[SIZE];

int bfs(int n, int k) {
    queue<int> q;
    q.push(n);
    visited[n] = true;

    while (!q.empty()) {
        int s = q.front();
        q.pop();

        // -1
        if (s > 0 && !visited[s - 1]) {
            graph[s - 1] = graph[s] + 1;
            visited[s - 1] = true;
            q.push(s - 1);
        }

        // +1
        if (s < SIZE - 1 && !visited[s + 1]) {
            graph[s + 1] = graph[s] + 1;
            visited[s + 1] = true;
            q.push(s + 1);
        }

        // x2
        if (2 * s < SIZE && !visited[s * 2]) {
            graph[2 * s] = graph[s] + 1;
            visited[2 * s] = true;
            q.push(2 * s);
        }
    }

    return graph[k];
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    memset(visited, false, sizeof(visited));
    memset(graph, 0, sizeof(graph));

    cout << bfs(n, k);
}
