#include "bits/stdc++.h"

using namespace std;

int r, c;
char graph[50][51];
int dist[50][50];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> r >> c;
    memset(dist, -1, sizeof(dist));
    queue<pair<int, int>> q;
    queue<pair<int, int>> water;

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    int sx, sy, ex, ey;

    for (int i = 0; i < r; i++) {
        cin >> graph[i];

        for (int j = 0; j < c; j++) {
            if (graph[i][j] == 'S') {
                sx = i;
                sy = j;
            } else if (graph[i][j] == 'D') {
                ex = i;
                ey = j;
            } else if (graph[i][j] == '*') {
                water.push({i, j});
            }
        }
    }

    dist[sx][sy] = 0;
    q.push({ sx, sy });

    while (true) {
        // Expand water
        int waterSize = water.size();
        for (int i = 0; i < waterSize; i++) {
            auto [x, y] = water.front();
            water.pop();

            for (int j = 0; j < 4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];

                if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                if (graph[nx][ny] == '*' || graph[nx][ny] == 'X' || graph[nx][ny] == 'D') continue;

                graph[nx][ny] = '*';
                water.push({nx, ny});
            }
        }

        // Move
        int qSize = q.size();
        for (int i = 0; i < qSize; i++) {
            auto [x, y] = q.front();
            q.pop();

            for (int j = 0; j < 4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];

                if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                if (graph[nx][ny] == '*' || graph[nx][ny] == 'X') continue;
                if (dist[nx][ny] != -1) continue;

                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});

                if (nx == ex && ny == ey) {
                    cout << dist[nx][ny];
                    return 0;
                }
            }
        }

        if (q.empty()) {
            cout << "KAKTUS";
            return 0;
        }
    }
}
