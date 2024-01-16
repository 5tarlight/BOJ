#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>

using namespace std;

int graph[50][50];
int n, l, r;
int day = 0;
bool visited[50][50];

void resetVisited() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            visited[i][j] = false;
}

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool bfs(int x, int y) {
    if (visited[x][y])
        return false;

    vector<pair<int, int>> target;
    long long s = graph[x][y];
    queue<pair<int, int>> q;
    target.emplace_back(x, y);
    q.emplace(x, y);
    visited[x][y] = true;

    while (!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = a + dx[i];
            int ny = b + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            else if (visited[nx][ny])
                continue;

            int dif = abs(graph[a][b] - graph[nx][ny]);
            if (dif >= l && dif <= r) {
                visited[nx][ny] = true;
                target.emplace_back(nx, ny);
                q.emplace(nx, ny);
                s += graph[nx][ny];
            }
        }
    }

    if (target.size() == 1)
        return false;
    else {
        bool identical = true;
        int start = graph[target[0].first][target[0].second];

        for (auto &p : target) {
            if (graph[p.first][p.second] != start) {
                identical = false;
                break;
            }
        }

        if (identical)
            return false;
    }

    long long avg = s / target.size();
    for (auto &p : target) {
        int a = p.first;
        int b = p.second;
        graph[a][b] = avg;
    }

    return true;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];
    }

    bool nextDay;
    while (true) {
        resetVisited();
        nextDay = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (bfs(i, j)) {
                    nextDay = true;
                }
            }
        }

        if (nextDay) {
            day++;
            nextDay = false;
        } else
            break;
    }

    cout << day;
}
