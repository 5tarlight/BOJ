#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int nxtDir[4][4] = {
    {0, 3, 2, 1},
    {2, 1, 0, 3},
    {1, 0, 3, 2},
    {3, 2, 1, 0}
};

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int main() {
    fio();

    int n, m; cin >> n >> m;
    int grid[n][m];
    queue<pair<pair<int, int>, int>> q; // (x, y), dir
    bool visited[n][m][4];
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];

            if (grid[i][j] == 9) {
                for (int d = 0; d < 4; d++) {
                    q.push({{i, j}, d});
                    visited[i][j][d] = true;
                }
            }
        }
    }

    while (!q.empty()) {
        auto [pos, dir] = q.front(); q.pop();
        auto [x, y] = pos;

        if (grid[x][y] == 0 || grid[x][y] == 9) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny][dir]) {
                visited[nx][ny][dir] = true;
                q.push({{nx, ny}, dir});
            }
        } else {
            int nextDir = nxtDir[grid[x][y] - 1][dir];
            int nx = x + dx[nextDir];
            int ny = y + dy[nextDir];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny][nextDir]) {
                visited[nx][ny][nextDir] = true;
                q.push({{nx, ny}, nextDir});
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int d = 0; d < 4; d++) {
                if (visited[i][j][d]) {
                    ans++;
                    break;
                }
            }
        }
    }

    cout << ans;
}