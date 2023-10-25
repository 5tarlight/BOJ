#include <iostream>
#include <queue>

#define M 100001

using namespace std;

bool visited[M];
int t[M];

int bfs(int cur, int to) {
    queue<int> q;
    q.emplace(cur);
    visited[cur] = true;

    while (!q.empty()) {
        int p = q.front();
        int d = t[p];
        q.pop();

        if (2 * p < M && (!visited[2 * p] || t[2 * p] > t[p])) {
            visited[2 * p] = true;
            t[2 * p] = d;
            q.emplace(2 * p);
        }
        if (p > 0 && (!visited[p - 1] || t[p - 1] > t[p] + 1)) {
            visited[p - 1] = true;
            t[p - 1] = d + 1;
            q.emplace(p - 1);
        }
        if (p < M - 1 && (!visited[p + 1]) || t[p + 1] > t[p] + 1) {
            visited[p + 1] = true;
            t[p + 1] = d + 1;
            q.emplace(p + 1);
        }
    }

    return t[to];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int s, e;
    cin >> s >> e;
    cout << bfs(s, e);
}
