#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int map[50][50];
int type[50][50];
bool visited[50][50];
int m, n;
int room = 0;
int wideRoom = -1;
int wideNear = -1;

void bfs(int x, int y, int t) {
    if (visited[x][y])
        return;

    room++;
    queue<pair<int, int>> q;
    q.emplace(x, y);
    visited[x][y] = true;
    int cnt = 1;
    vector<pair<int, int>> rooms;
    rooms.emplace_back(x, y);

    while (!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        vector<pair<int, int>> d;
        if (map[a][b] >= 8) {
            d.emplace_back(1, 0);
            map[a][b] -= 8;
        }
        if (map[a][b] >= 4) {
            d.emplace_back(0, 1);
            map[a][b] -= 4;
        }
        if (map[a][b] >= 2) {
            d.emplace_back(-1, 0);
            map[a][b] -= 2;
        }
        if (map[a][b] >= 1) {
            d.emplace_back(0, -1);
        }

        for (auto &dp : d) {
            int na = a + dp.first;
            int nb = b + dp.second;

            if (!visited[na][nb]) {
                visited[na][nb] = true;
                q.emplace(na, nb);
                rooms.emplace_back(na, nb);
                cnt++;
            }
        }
    }

    for (auto &p : rooms) {
        type[p.first][p.second] = t;
        map[p.first][p.second] = cnt;
    }
    if (cnt > wideRoom)
        wideRoom = cnt;
}

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 0 };
void merge(int x, int y) {
    int cur = map[x][y];
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= m || ny < 0 || ny >= n)
            continue;

        int nxt = map[nx][ny];

        if (type[x][y] != type[nx][ny] && wideNear < cur + nxt)
            wideNear = cur + nxt;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int num;
            cin >> num;

            map[i][j] = 15 - num;
        }
    }

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            bfs(i, j, i * 100 + j);

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            merge(i, j);

    cout << room << '\n';
    cout << wideRoom << '\n';
    cout << wideNear << '\n';
}
