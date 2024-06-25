#include <iostream>
#include <queue>

using namespace std;

vector<pair<int, int>> graph[101][101];
int n, m;
bool on[101][101];
bool visited[101][101];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool canGo(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 1 || nx > n || ny < 1 || ny > n) continue;

        if (visited[nx][ny])
            return true;
    }

    return false;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    while (m--) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        graph[x][y].push_back({ a, b });
    }

    on[1][1] = true;
    queue<pair<int, int>> q;
    q.push({ 1, 1 });
    visited[1][1] = true;

    int ans = 1;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (auto [px, py] : graph[x][y]) {
            if (on[px][py] || visited[px][py]) continue;

            ans++;
            on[px][py] = true;
        }

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (on[i][j] && !visited[i][j] && canGo(i, j)) {
                    q.push({ i, j });
                    visited[i][j] = true;
                }
    }

    cout << ans;
}
