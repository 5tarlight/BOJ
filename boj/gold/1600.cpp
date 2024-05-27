#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int k, h, w;
    cin >> k >> w >> h;
    int dx[] = { 1, -1, 0, 0 };
    int dy[] = { 0, 0, 1, -1 };
    int kx[] = { 2, 2, 1, 1, -1, -1, -2, -2 };
    int ky[] = { 1, -1, 2, -2, 2, -2, 1, -1 };
    vector<vector<int>> a(h, vector<int>(w));
    vector<vector<vector<int>>> d(k + 1, vector<vector<int>>(h, vector<int>(w, -1)));

    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> a[i][j];

    queue<pair<int, pair<int, int>>> q;
    q.push({ 0, { 0, 0 } });
    d[0][0][0] = 0;

    while (!q.empty()) {
        auto [knight, p] = q.front();
        auto [x, y] = p;
        q.pop();

        if (x == h - 1 && y == w - 1) {
            cout << d[knight][x][y];
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w || a[nx][ny] == 1 || d[knight][nx][ny] != -1)
                continue;
            d[knight][nx][ny] = d[knight][x][y] + 1;
            q.push({ knight, { nx, ny } });
        }

        if (knight < k) {
            for (int i = 0; i < 8; i++) {
                int nx = x + kx[i];
                int ny = y + ky[i];
                if (nx < 0 || nx >= h || ny < 0 || ny >= w || a[nx][ny] == 1 || d[knight + 1][nx][ny] != -1)
                    continue;
                d[knight + 1][nx][ny] = d[knight][x][y] + 1;
                q.push({ knight + 1, { nx, ny } });
            }
        }
    }

    cout << -1 << endl;
}