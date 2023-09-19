#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m, n;
    cin >> m >> n;
    int graph[n][m];
    queue<pair<int, int>> q;
    bool visited[n][m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            memset(visited[i], false, sizeof(visited[i]));
            int num;
            cin >> num;
            graph[i][j] = num;

            if (num == 1)
                q.emplace(i, j);
        }

    int dx[] = { -1, 1, 0, 0 };
    int dy[] = { 0, 0, -1, 1 };
    int maxi = 1;

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        visited[x][y] = true;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (!visited[nx][ny] && graph[nx][ny] == 0) {
                graph[nx][ny] = graph[x][y] + 1;
                q.emplace(nx, ny);

                if (graph[x][y] + 1 > maxi)
                    maxi = graph[x][y] + 1;
            }
        }
    }

    bool done = true;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (graph[i][j] == 0)
                done = false;

    if (done) {
        cout << maxi - 1;
    } else {
        cout << -1;
    }
}
