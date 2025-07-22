#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int r, c;
int a[100][100];

int getCnt() {
    int cnt = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (a[i][j] == 1)
                cnt++;

    return cnt;
}

bool isDone() {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (a[i][j] == 1)
                return false;

    return true;
}

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int visited[100][100];

void melt() {
    memset(visited, 0, sizeof(visited));

    queue<pair<int, int>> q;
    for (int i = 0; i < r; i++) {
        if (a[i][0] == 0) {
            q.push({i, 0});
            visited[i][0] = 1;
        }
        if (a[i][c - 1] == 0) {
            q.push({i, c - 1});
            visited[i][c - 1] = 1;
        }
    }

    for (int j = 0; j < c; j++) {
        if (a[0][j] == 0) {
            q.push({0, j});
            visited[0][j] = 1;
        }
        if (a[r - 1][j] == 0) {
            q.push({r - 1, j});
            visited[r - 1][j] = 1;
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c || visited[nx][ny])
                continue;

            if (a[nx][ny] == 1) {
                a[nx][ny] = 0;
                visited[nx][ny] = 1;
            } else {
                q.push({nx, ny});
                visited[nx][ny] = 1;
            }
        }
    }
}

int main() {
    fio();

    cin >> r >> c;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> a[i][j];

    int prev;
    int ans = 0;
    while (!isDone()) {
        prev = getCnt();
        melt();
        ans++;
    }

    cout << ans << '\n' << prev;
}
