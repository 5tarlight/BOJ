#include <iostream>
#include <queue>

using namespace std;

struct Point {
    int x;
    int y;
    int z;

    Point(int x, int y, int z): x(x), y(y), z(z) {}
};

int box[100][100][100];
bool visited[100][100][100];
queue<Point> q;
int maxTime = 1;
int dx[] = { -1, 1, 0, 0, 0, 0 };
int dy[] = { 0, 0, -1, 1, 0, 0 };
int dz[] = { 0, 0, 0, 0, -1, 1 };

void bfs(int m, int n, int h) {
    while (!q.empty()) {
        Point p = q.front();
        q.pop();
        int cur = box[p.x][p.y][p.z];

        for (int i = 0; i < 6; i++) {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            int nz = p.z + dz[i];

            if (
                    nx >= 0 && nx < h &&
                    ny >= 0 && ny < n &&
                    nz >= 0 && nz < m &&
                    box[nx][ny][nz] == 0 &&
                    !visited[nx][ny][nz]
            ) {
                visited[nx][ny][nz] = true;
                box[nx][ny][nz] = cur + 1;
                q.emplace(nx, ny, nz);

                if (cur + 1 > maxTime)
                    maxTime = cur + 1;
            }
        }
    }
}

bool done(int m, int n, int h) {
    for (int i = 0; i < h; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < m; k++)
                if (box[i][j][k] == 0)
                    return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m, n, h;
    cin >> m >> n >> h;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                int num;
                cin >> num;
                box[i][j][k] = num;

                if (num == 1) {
                    visited[i][j][k] = true;
                    q.emplace(i, j, k);
                }
            }
        }
    }

    bfs(m, n, h);

    if (done(m, n, h))
        cout << maxTime - 1;
    else
        cout << -1;

    return 0;
}
