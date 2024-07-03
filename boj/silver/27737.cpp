#include <iostream>
#include <queue>

using namespace std;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
bool visited[100][100];
int n, m, k;
int graph[100][100];

int getCnt(int x, int y) {
    if (visited[x][y] || graph[x][y] == 1)
        return 0;

    int cnt = 1;
    queue<pair<int, int>> q;
    q.push({ x, y });
    visited[x][y] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny] || graph[nx][ny] == 1)
                continue;

            cnt++;
            visited[nx][ny] = true;
            q.push({ nx, ny });
        }
    }

    if (cnt % k == 0)
        return cnt / k;
    else
        return cnt / k + 1;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    int require = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            require += getCnt(i, j);

    if (require == 0)
        cout << "IMPOSSIBLE";
    else if (require > m)
        cout << "IMPOSSIBLE";
    else {
        cout << "POSSIBLE\n";
        cout << m - require;
    }
}
