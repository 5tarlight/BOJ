#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int r, c;
char graph[101][101];
bool visited[100][100];
int cluster[100][100];

void shoot(int h, bool isLeft) {
    if (isLeft) {
        for (int j = 0; j < c; j++) {
            if (graph[h][j] == 'x') {
                graph[h][j] = '.';
                break;
            }
        }
    } else {
        for (int j = c - 1; j >= 0; j--) {
            if (graph[h][j] == 'x') {
                graph[h][j] = '.';
                break;
            }
        }
    }
}

void resetVisit() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            visited[i][j] = false;
        }
    }
}

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void markCluster(int x, int y, int id) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    cluster[x][y] = id;

    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (visited[nx][ny] || graph[nx][ny] == '.') continue;

            visited[nx][ny] = true;
            cluster[nx][ny] = id;
            q.push({nx, ny});
        }
    }
}

void makeCluster() {
    int id = 1;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (!visited[i][j] && graph[i][j] == 'x') {
                markCluster(i, j, id++);
            }
        }
    }
}

void moveDownCluster(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    vector<pair<int, int>> points;
    visited[x][y] = true;
    points.push_back({x, y});

    bool isFloating = true;
    int gap = 1e9;
    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();

        if (cx == r - 1 || cluster[cx + 1][cy] != cluster[x][y] && cluster[cx + 1][cy] != 0)
            isFloating = false;

        if (isFloating) {
            int dist = 1;
            bool isBottom = true;
            while (cx + dist < r) {
                if (cluster[cx + dist][cy] != 0) {
                    if (cluster[cx + dist][cy] == cluster[x][y]) {
                        isBottom = false;
                    }

                    break;
                }
                dist++;
            }
            dist--;

            if (isBottom && cluster[cx + dist][cy] != cluster[x][y]) {
                gap = min(gap, dist);
            }
        }

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (visited[nx][ny] || graph[nx][ny] == '.') continue;
            if (cluster[nx][ny] != cluster[x][y]) continue;

            visited[nx][ny] = true;
            q.push({nx, ny});
            points.push_back({nx, ny});
        }
    }

    if (isFloating) {
        sort(points.begin(), points.end(), greater<>());
        for (auto [x, y] : points) {
            graph[x][y] = '.';
            graph[x + gap][y] = 'x';
        }
    }
}

void resetCluster() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cluster[i][j] = 0;
        }
    }
}

void print() {
    for (int i = 0; i < r; i++) {
        cout << graph[i] << '\n';
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        cin >> graph[i];
    }

    int t;
    cin >> t;
    bool isLeft = true;
    while (t--) {
        int h;
        cin >> h;
        h = r - h;
        shoot(h, isLeft);
        isLeft = !isLeft;
        resetVisit();
        resetCluster();
        makeCluster();
        resetVisit();

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (!visited[i][j] && cluster[i][j] != 0) {
                    moveDownCluster(i, j);
                }
            }
        }
    }

    print();
}
