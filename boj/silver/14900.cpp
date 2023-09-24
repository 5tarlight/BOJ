#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
int graph[1000][1000];
bool visited[1000][1000];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.emplace(x, y);
    visited[x][y] = true;
    graph[x][y] = 0;

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];

            if (
                nx < 0 || nx >= n ||
                ny < 0 || ny >= m ||
                visited[nx][ny] ||
                graph[nx][ny] == 0
            )
                continue;

            graph[nx][ny] = graph[p.first][p.second] + 1;
            visited[nx][ny] = true;
            q.emplace(nx, ny);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    pair<int, int> start;
    for (int i = 0; i < n; i++) {
        memset(visited[i], false, sizeof(visited[i]));

        for (int j = 0; j < m; j++) {
            int v;
            cin >> v;
            graph[i][j] = v;

            if (v == 2)
                start = make_pair(i, j);
        }
    }

    bfs(start.first, start.second);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && graph[i][j] == 1)
                graph[i][j] = -1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << graph[i][j] << ' ';
        }
        cout << '\n';
    }
}
