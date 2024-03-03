#include <iostream>

using namespace std;

int graph[2000][2000];
// U R D L
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;

bool checkNear(int x, int y) {
    bool found = false;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
            continue;
        }

        if (graph[nx][ny] == 0) {
            found = true;
            break;
        }
    }

    return found;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    char d;
    cin >> n >> m >> d;

    int x, y;
    int ix, iy;
    if (d == 'U') {
        x = 0;
        y = m / 2;
    } else if (d == 'D') {
        x = n - 1;
        y = m / 2;
    } else if (d == 'L') {
        x = n / 2;
        y = 0;
    } else if (d == 'R') {
        x = n / 2;
        y = m - 1;
    }
    ix = x;
    iy = y;

    graph[x][y] = 1;
    int prev = 1;
    int dir, idir;
    if (d == 'U') {
        dir = 2;
    } else if (d == 'D') {
        dir = 0;
    } else if (d == 'L') {
        dir = 1;
    } else if (d == 'R') {
        dir = 3;
    }
    idir = dir;

    while (true) {
        if (!checkNear(x, y)) {
            break;
        }

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m || graph[nx][ny] != 0) {
            dir++;
            if (dir == 4) {
                dir = 0;
            }
            continue;
        }

        graph[nx][ny] = prev + 1;
        prev++;
        x = nx;
        y = ny;
    }

    prev = 1;
    x = ix;
    y = iy;
    dir = idir;

    while (true) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            break;

        x = nx;
        y = ny;
        graph[nx][ny] = 0;
    }

    x = ix;
    y = iy;
    dir = idir;

    while (true) {
        if (!checkNear(x, y)) {
            break;
        }

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m || graph[nx][ny] != 0) {
            dir--;
            if (dir == -1) {
                dir = 3;
            }
            continue;
        }

        graph[nx][ny] = prev + 1;
        prev++;
        x = nx;
        y = ny;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
}
