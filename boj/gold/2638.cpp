#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

int n, m;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int graph[100][100];

void markOut() {
    bool visited[n][m];
    graph[0][0] = -1;
    queue<tuple<int, int>> q;
    q.emplace(0, 0);

    for (int i = 0; i < n; i++)
        fill(visited[i], visited[i] + m, false);

    visited[0][0] = true;
    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny] || graph[nx][ny] == 1)
                continue;

            visited[nx][ny] = true;
            graph[nx][ny] = -1;
            q.emplace(nx, ny);
        }
    }
}

void melt() {
    vector<tuple<int, int>> v;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 1) {
                int cnt = 0;
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m || graph[nx][ny] == 1 || graph[nx][ny] == 0)
                        continue;
                    cnt++;
                }

                if (cnt >= 2)
                    v.emplace_back(i, j);
            }
        }
    }

    for (auto &t : v) {
        int x, y;
        tie(x, y) = t;
        graph[x][y] = 0;
    }
}

bool done() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (graph[i][j] == 1)
                return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> graph[i][j];

    int t = 0;
    while (!done()) {
        markOut();
        melt();
        t++;
    }

    cout << t;
}
