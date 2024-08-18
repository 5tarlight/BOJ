#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int dp[401][401], step[401][401];
    int dx[] = { -2,-2,-1,1,2,2,1,-1 };
    int dy[] = { -1,1,2,2,1,-1,-2,-2 };
    const int MOD = 1e9 + 9;

    memset(step, -1, sizeof(step));
    step[1][1] = 0;
    dp[1][1] = 1;

    queue<pair<int, int>> q;
    q.push({ 1, 1 });

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        if (cur.first == n && cur.second == m) {
            cout << step[cur.first][cur.second] << ' ' << dp[cur.first][cur.second];
            return 0;
        }

        for (int i = 0; i < 8; i++) {
            int tx = cur.first + dx[i];
            int ty = cur.second + dy[i];

            if (tx <= 0 || tx > n || ty <= 0 || ty > m || (step[tx][ty] != -1 && step[tx][ty] < step[cur.first][cur.second] + 1))
                continue;

            step[tx][ty] = step[cur.first][cur.second] + 1;
            if (dp[tx][ty] != 0)
                dp[tx][ty] = (dp[tx][ty] % MOD + dp[cur.first][cur.second] % MOD) % MOD;
            else {
                dp[tx][ty] = dp[cur.first][cur.second];
                q.push({ tx, ty });
            }
        }
    }

    cout << "None";
    return 0;
}
