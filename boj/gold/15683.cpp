#include <iostream>
#include <cstring>

using namespace std;

#define INF 1'000'000'000

int n, m;
int graph[8][8];
pair<int, int> cctv[8];
int direction[8];
int cctvCnt = 0;
int wallCnt = 0;
int minInvisible = INF;
bool seen[8][8];

void visitForward(int x, int y, int dir) {
    // r
    if (dir == 0 && y < m - 1) {
        for (int j = y + 1; j < m; j++) {
            if (graph[x][j] == 6)
                break;
            else if (graph[x][j] == 0)
                seen[x][j] = true;
        }
    }
    // d
    if (dir == 1 && x < n - 1) {
        for (int j = x + 1; j < n; j++) {
            if (graph[j][y] == 6)
                break;
            else if (graph[j][y] == 0)
                seen[j][y] = true;
        }
    }
    // l
    if (dir == 2 && y > 0) {
        for (int j = y - 1; j >= 0; j--) {
            if (graph[x][j] == 6)
                break;
            else if (graph[x][j] == 0)
                seen[x][j] = true;
        }
    }
    // u
    if (dir == 3 && x > 0) {
        for (int j = x - 1; j >= 0; j--) {
            if (graph[j][y] == 6)
                break;
            else if (graph[j][y] == 0)
                seen[j][y] = true;
        }
    }
}

int countInvisible() {
    int visible = 0;
    for (auto & i : seen)
        memset(i, false, sizeof(i));


    for (int i = 0; i < cctvCnt; i++) {
        int x = cctv[i].first;
        int y = cctv[i].second;
        int type = graph[x][y];
        int rotation = direction[i];

        if (type == 1) {
            visitForward(x, y, rotation);
        } else if (type == 2) {
            if (rotation == 0)  {
                visitForward(x, y, 0);
                visitForward(x, y, 2);
            } else {
                visitForward(x, y, 1);
                visitForward(x, y, 3);
            }
        } else if (type == 3) {
            visitForward(x, y, rotation);
            visitForward(x, y, (rotation + 1) % 4);
        } else if (type == 4) {
            visitForward(x, y, rotation);
            visitForward(x, y, (rotation + 1) % 4);
            visitForward(x, y, (rotation + 2) % 4);
        } else {
            visitForward(x, y, 0);
            visitForward(x, y, 1);
            visitForward(x, y, 2);
            visitForward(x, y, 3);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (seen[i][j])
                visible++;
        }
    }

    return n * m - cctvCnt - wallCnt - visible;
}

void backtrack(int d) {
    if (d == cctvCnt) {
        int inv = countInvisible();
        if (inv < minInvisible)
            minInvisible = inv;
        return;
    }

    int curX = cctv[d].first;
    int curY = cctv[d].second;
    int curType = graph[curX][curY];
    int maxIter;
    switch (curType) {
        case 1:
        case 3:
        case 4:
            maxIter = 4;
            break;
        case 2:
            maxIter = 2;
            break;
        case 5:
            maxIter = 1;
            break;
        default:
            maxIter = 4;
    }

    for (int i = 0; i < maxIter; i++) {
        direction[d] = i;
        backtrack(d + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(direction, 0, sizeof(direction));
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int num;
            cin >> num;

            if (num > 0 && num < 6) {
                cctv[cctvCnt] = make_pair(i, j);
                cctvCnt++;
            } else if (num == 6)
                wallCnt++;

            graph[i][j] = num;
        }
    }

    backtrack(0);
    cout << minInvisible;
}
