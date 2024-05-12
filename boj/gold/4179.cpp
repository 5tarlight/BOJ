#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int r, c;
char graph[1000][1001];
int fire[1000][1000];
bool visited[1000][1000];
int dist[1000][1000];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void resetVisited() {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            visited[i][j] = false;
}

void init() {
    for (int i = 0; i < r; i++)
        fill(fire[i], fire[i] + c, 1e9);
}

void expandFire() {
    for (int x = 0; x < r; x++) {
        for (int y = 0; y < c; y++) {
            if (graph[x][y] != 'F') continue;

            resetVisited();
            queue<pair<int, int>> q;
            q.emplace(x, y);
            fire[x][y] = 0;
            visited[x][y] = true;

            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (nx < 0 || nx >= r || ny < 0 || ny >= c || visited[nx][ny] || graph[nx][ny] == '#')
                        continue;

                    fire[nx][ny] = min(fire[nx][ny], fire[x][y] + 1);
                    visited[nx][ny] = true;
                    q.emplace(nx, ny);
                }
            }
        }
    }
}

int canEscape(int x, int y) {
    resetVisited();
    queue<pair<int, int>> q;
    q.emplace(x, y);
    dist[x][y] = 0;
    visited[x][y] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c)
                return dist[x][y] + 1;
            if (visited[nx][ny] || graph[nx][ny] == '#') continue;
            if (fire[nx][ny] <= dist[x][y] + 1) continue;

            dist[nx][ny] = dist[x][y] + 1;
            q.emplace(nx, ny);
            visited[nx][ny] = true;
        }
    }

    return -1;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> r >> c;
    int x, y;
    for (int i = 0; i < r; i++) {
        cin >> graph[i];

        for (int j = 0; j < c; j++) {
            if (graph[i][j] == 'J') {
                x = i;
                y = j;
            }
        }
    }

    init();
    expandFire();

    int time = canEscape(x, y);
    if (time == -1)
        cout << "IMPOSSIBLE";
    else
        cout << time;
}
