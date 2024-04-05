#include <iostream>
#include <string>

using namespace std;

char graph[50][50];
int n, m;
bool found = false;
bool visited[50][50];

void reset() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = false;
        }
    }
}

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void bfs(int sx, int xy, int x, int y, int d) {
    if (found)
        return;

    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;

        if (nx == sx && ny == xy && d >= 4) {
            found = true;
            return;
        }

        if (graph[nx][ny] == graph[x][y]) {
            if (!visited[nx][ny]) {
                bfs(sx, xy, nx, ny, d + 1);
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < m; j++) {
            graph[i][j] = line[j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            reset();
            bfs(i, j, i, j, 1);
            if (found) {
                cout << "Yes";
                return 0;
            }
        }
    }

    cout << "No";
}
