#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int graph[300][300];
int n, m;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

bool isIn(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int cntNear0(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (!isIn(nx, ny)) continue;
        if (graph[nx][ny] == 0) cnt++;
    }
    return cnt;
}

bool visited[300][300];

void resetVisited() {
    memset(visited, false, sizeof(visited));
}

int cntCluster() {
    int ans = 0;
    resetVisited();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 0 || visited[i][j]) continue;
            ans++;
            queue<pair<int, int>> q;
            q.push({i, j});
            visited[i][j] = true;
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k], ny = y + dy[k];
                    if (!isIn(nx, ny) || visited[nx][ny] || graph[nx][ny] == 0) continue;
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }

    return ans;
}

bool isAllMelt() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (graph[i][j] != 0) return false;
    return true;
}

void melt() {
    int temp[300][300];
    memcpy(temp, graph, sizeof(graph));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (graph[i][j] != 0)
                temp[i][j] = max(graph[i][j] - cntNear0(i, j), 0);

    memcpy(graph, temp, sizeof(temp));
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> graph[i][j];

    int ans = 0;
    while (!isAllMelt()) {
        melt();
        ans++;
        if (cntCluster() >= 2) {
            cout << ans;
            return 0;
        }
    }

    cout << 0;
}
