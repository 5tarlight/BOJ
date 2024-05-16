#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int graph[5][5];
    int visited[5][5] = { false, };
    int dist[5][5];
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> graph[i][j];
    int x, y;
    cin >> x >> y;

    visited[x][y] = true;
    queue<pair<int, int>> q;
    q.push({ x, y });
    dist[x][y] = 0;

    int ans = -1;
    while (!q.empty() && ans == -1) {
        auto [x, y] = q.front();
        int cost = dist[x][y];
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + ("0211"[i] - '1');
            int ny = y + ("1102"[i] - '1');

            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || visited[nx][ny] || graph[nx][ny] == -1)
                continue;

            dist[nx][ny] = cost + 1;
            q.push({ nx, ny });
            visited[nx][ny] = true;

            if (graph[nx][ny] == 1) {
                ans = cost + 1;
                break;
            }
        }
    }

    cout << ans;
}
