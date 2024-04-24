#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int graph[100][100];
int island[100][100];
int n;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int ans = 1e9;

void markIsland() {
    int id = 1;
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 1 && island[i][j] == 0) {
                q.push({i, j});
                island[i][j] = id;

                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                            continue;
                        if (graph[nx][ny] == 1 && island[nx][ny] == 0) {
                            q.push({nx, ny});
                            island[nx][ny] = id;
                        }
                    }
                }

                id++;
            }
        }
    }
}

bool isOpen(int x, int y) {
    bool open = false;
    int id = island[x][y];
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
            continue;
        if (island[nx][ny] == 0)
            open = true;
    }

    return open;
}

int getNear(int x, int y) {
    int id = island[x][y];
    queue<pair<int, int>> q;
    bool visited[100][100] = { false, };
    int dist[100][100] = { 0, };

    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if (island[nx][ny] == 0 && !visited[nx][ny]) {
                q.push({nx, ny});
                visited[nx][ny] = true;
                dist[nx][ny] = dist[cx][cy] + 1;
            }
            if (island[nx][ny] != 0 && island[nx][ny] != id) {
                return dist[cx][cy];
            }
        }
    }

    return 1e9;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    markIsland();

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (island[i][j] != 0 && isOpen(i, j))
                ans = min(ans, getNear(i, j));

    cout << ans;
}
