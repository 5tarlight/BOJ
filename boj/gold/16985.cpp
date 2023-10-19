#include <iostream>
#include <cstring>
#include <algorithm>
#include <tuple>
#include <queue>

using namespace std;

#define INF 1'000'000'000

int original[5][5][5];
int graph[5][5][5];
int mind = INF;
int dx[] = { -1, 1, 0, 0, 0, 0 };
int dy[] = { 0, 0, -1, 1, 0, 0 };
int dz[] = { 0, 0, 0, 0, -1, 1 };
int sec[5];
bool visited[5][5][5];

void bfs() {
    for (int e = 0; e < 4; e++) {
        queue<tuple<int, int, int>> q;
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                fill(visited[i][j], visited[i][j] + 5, false);
        for (int i = 0; i < 5; i++)
            memmove(graph[i], original[i], sizeof(graph[i]));

        int x0 = 0;
        int y0;
        int z0;
        if (e == 0 && graph[sec[0]][0][0] == 1) {
            q.emplace(0, 0, 0);
            y0 = 0;
            z0 = 0;
            visited[0][0][0] = true;
        } else if (e == 1 && graph[sec[0]][4][0] == 1) {
            q.emplace(0, 4, 0);
            y0 = 4;
            z0 = 0;
            visited[0][4][0] = true;
        } else if (e == 2 && graph[sec[0]][0][4] == 1) {
            q.emplace(0, 0, 4);
            y0 = 0;
            z0 = 4;
            visited[0][0][4] = true;
        } else if (e == 3 && graph[sec[0]][4][4] == 1) {
            q.emplace(0, 4, 4);
            y0 = 4;
            z0 = 4;
            visited[0][4][4] = true;
        }

        bool done = false;
        while (!done && !q.empty()) {
            int x, y, z;
            tie(x, y, z) = q.front();
            q.pop();
            int dist = graph[sec[x]][y][z] + 1;

            for (int i = 0; i < 6; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                int nz = z + dz[i];

                if (
                    nx < 0 || ny < 0 || nz < 0 ||
                    nx >= 5 || ny >= 5 || nz >= 5 ||
                    graph[sec[nx]][ny][nz] == 0 ||
                    visited[nx][ny][nz]
                )
                    continue;

                if ((nx == 0 || nx == 4) && (ny == 0 || ny == 4) && (nz == 0 || nz == 4)) {
                    int sameCnt = 0;
                    if (nx == x0)
                        sameCnt++;
                    if (ny == y0)
                        sameCnt++;
                    if (nz == z0)
                        sameCnt++;

                    if (sameCnt == 0) {
                        if (dist < mind)
                            mind = dist;

                        done = true;
                        break;
                    }
                }

                visited[nx][ny][nz] = true;
                graph[sec[nx]][ny][nz] = dist;
                q.emplace(nx, ny, nz);
            }
        }
    }
}

void rotate(int n) {
    int temp[5][5];

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            temp[i][j] = original[sec[n]][4 - j][i];

    memmove(original[sec[n]], temp, sizeof(original[sec[n]]));
}

void backtrackRotation(int d) {
    if (d == 4) {
        bfs();
        return;
    }

    for (int i = 0; i < 4; i++) {
        backtrackRotation(d + 1);
        rotate(d + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++)
                cin >> original[i][j][k];

    int perm[] = { 0, 1, 2, 3, 4 };
    do {
        for (int i = 0; i < 5; i++)
            sec[perm[i]] = i;

        backtrackRotation(0);
    } while (next_permutation(perm, perm + 5));

    if (mind == INF)
        cout << -1;
    else
        cout << mind - 1;
}
