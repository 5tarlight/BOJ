#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    while (true) {
        int w, h;
        cin >> w >> h;
        if (w == 0 && h == 0) break;

        int grid[h][w];
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j)
                cin >> grid[i][j];

        int cnt = 0;
        bool visited[h][w];
        memset(visited, false, sizeof(visited));

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    cnt++;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = true;

                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();

                        for (int dx = -1; dx <= 1; dx++) {
                            for (int dy = -1; dy <= 1; dy++) {
                                int nx = x + dx;
                                int ny = y + dy;
                                if (nx >= 0 && nx < h && ny >= 0 && ny < w && grid[nx][ny] == 1 && !visited[nx][ny]) {
                                    visited[nx][ny] = true;
                                    q.push({nx, ny});
                                }
                            }
                        }
                    }
                }
            }
        }

        cout << cnt << '\n';
    }
}
