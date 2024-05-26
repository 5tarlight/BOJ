#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int dx[] = { -1, 1, 0, 0, 0, 0 };
int dy[] = { 0, 0, -1, 1, 0, 0 };
int dz[] = { 0, 0, 0, 0, -1, 1 };
int l, r, c;
char graph[31][31][31];
int visited[31][31][31];
int sx, xy, xz;
int ex, ey, ez;

void reset() {
    for (int i = 0; i < l; i++)
        for (int j = 0; j < r; j++)
            fill(visited[i][j], visited[i][j] + c, 0);
}

int bfs() {
    queue<pair<pair<int, int>, int>> q;
    q.push({ { sx, xy }, xz });
    visited[sx][xy][xz] = 1;

    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int z = q.front().second;
        q.pop();

        if (x == ex && y == ey && z == ez)
            return visited[x][y][z] - 1;

        for (int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if (nx < 0 || ny < 0 || nz < 0 || nx >= l || ny >= r || nz >= c)
                continue;
            if (visited[nx][ny][nz] || graph[nx][ny][nz] == '#')
                continue;

            visited[nx][ny][nz] = visited[x][y][z] + 1;
            q.push({ { nx, ny }, nz });
        }
    }

    return -1;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    while (true) {
        cin >> l >> r >> c;
        if (l == 0 && r == 0 && c == 0)
            break;

        for (int i = 0; i < l; i++) {
            for (int j = 0; j < r; j++) {
                cin >> graph[i][j];

                for (int k = 0; k < c; k++) {
                    if (graph[i][j][k] == 'S') {
                        sx = i;
                        xy = j;
                        xz = k;
                    } else if (graph[i][j][k] == 'E') {
                        ex = i;
                        ey = j;
                        ez = k;
                    }
                }
            }
        }

        reset();
        int result = bfs();
        if (result == -1)
            cout << "Trapped!" << '\n';
        else
            cout << "Escaped in " << result << " minute(s)." << '\n';
    }
}
