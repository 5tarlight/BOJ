#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    string graph[n];
    queue<pair<int, int>> q;
    bool visited[n][m];
    int dx[] = { -1, 1, 0, 0 };
    int dy[] = { 0, 0, -1, 1 };

    int sx, sy;
    for (int i = 0; i < n; i++) {
        cin >> graph[i];

        for (int j = 0; j < m; j++) {
            visited[i][j] = false;
            if (graph[i][j] == 'I') {
                sx = i;
                sy = j;
            }
        }
    }

    q.emplace(sx, sy);
    visited[sx][sy] = true;
    int count = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (
                nx < 0 || nx >= n ||
                ny < 0 || ny >= m ||
                visited[nx][ny] ||
                graph[nx][ny] =='X'
            )
                continue;

            if (graph[nx][ny] == 'P') {
                count++;
            }

            visited[nx][ny] = true;
            q.emplace(nx, ny);
        }
    }

    if (count == 0)
        cout << "TT";
    else
        cout << count;
}
