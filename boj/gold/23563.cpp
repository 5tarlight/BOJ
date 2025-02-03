#include "bits/stdc++.h"

using namespace std;

int r, c;
char grid[500][501];
int sx, sy, ex, ey;
int dist[500][500];
bool nearWall[500][500];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> r >> c;
    memset(dist, 0x3f, sizeof(dist));

    for (int i = 0; i < r; i++) {
        cin >> grid[i];
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == 'S') {
                sx = i;
                sy = j;
                dist[sx][sy] = 0;
            } else if (grid[i][j] == 'E') {
                ex = i;
                ey = j;
            }
            if (grid[i][j] == '#') continue;

            for (int d = 0; d < 4; d++) {
                int ni = i + dx[d], nj = j + dy[d];
                if (ni >= 0 && ni < r && nj >= 0 && nj < c && grid[ni][nj] == '#') {
                    nearWall[i][j] = true;
                    break;
                }
            }
        }
    }

    deque<pair<int, int>> q;
    q.push_back({sx, sy});

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop_front();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (grid[nx][ny] == '#') continue;

            int cost = (nearWall[x][y] && nearWall[nx][ny]) ? 0 : 1;
            if (dist[nx][ny] > dist[x][y] + cost) {
                dist[nx][ny] = dist[x][y] + cost;
                if (cost == 0)
                    q.push_front({nx, ny});
                else
                    q.push_back({nx, ny});
            }

            if (nx == ex && ny == ey) {
                cout << dist[ex][ey];
                return 0;
            }
        }
    }
}
