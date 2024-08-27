#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;
char a[50][50];
char b[50][50];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
bool ok = true;
bool visited[50][50];

void bfs(int s, int e) {
    queue<pair<int, int>> q;
    q.emplace(s, e);
    visited[s][e] = true;
    char target = a[s][e];
    char target2 = b[s][e];

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (a[nx][ny] != target || visited[nx][ny])
                continue;

            if (b[nx][ny] != target2) {
                ok = false;
                return;
            }

            visited[nx][ny] = true;
            q.emplace(nx, ny);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> b[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bfs(i, j);
            if (!ok) {
                cout << "NO";
                return 0;
            }
        }
    }

    cout << "YES";
}

