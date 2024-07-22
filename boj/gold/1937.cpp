#include <iostream>
#include <algorithm>

using namespace std;

int n;
int graph[500][500];
int dp[500][500];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int dfs(int x, int y) {
    if (dp[x][y] != 0)
        return dp[x][y];
    dp[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < n)
            if (graph[x][y] < graph[nx][ny])
                dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
    }

    return dp[x][y];
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans = max(ans, dfs(i, j));

    cout << ans;
}
