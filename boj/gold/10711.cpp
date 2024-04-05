#include <iostream>
#include <queue>

using namespace std;

int ans = 0;
int h, w;
int graph[1000][1000];
queue<pair<int, int>> q;

int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };

void wave() {
    while (!q.empty()) {
        int waveSize = q.size();
        while (waveSize--) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
                    continue;
                }

                if (graph[nx][ny] != 0) {
                    graph[nx][ny]--;

                    if (graph[nx][ny] == 0) {
                        q.push({ nx, ny });
                    }
                }
            }
        }
        ans++;
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < w; j++) {
            graph[i][j] = s[j] == '.' ? 0 : s[j] - '0';

            if (graph[i][j] == 0) {
                q.push({ i, j });
            }
        }
    }

    wave();

    cout << ans - 1 << '\n';
}
