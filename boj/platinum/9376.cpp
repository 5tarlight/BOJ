#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

char graph[102][102];
int door[3][102][102];
int w, c;
pair<int, int> p[2];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct Node {
    int r;
    int c;
    int cost;

    bool operator<(const Node &n) const {
        return cost > n.cost;
    }
};

void dijkstra(int pidx, int r, int cc) {
    priority_queue<Node> pq;
    pq.push({r, cc, 0});
    door[pidx][r][cc] = 0;

    while (!pq.empty()) {
        int x = pq.top().r;
        int y = pq.top().c;
        int cost = pq.top().cost;
        pq.pop();

        if (door[pidx][x][y] < cost)
            continue;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx > w + 1 || ny < 0 || ny > c + 1)
                continue;

            int nxt = cost;

            if (graph[nx][ny] == '*')
                continue;
            else if (graph[nx][ny] == '#')
                nxt++;

            if (nxt < door[pidx][nx][ny]) {
                door[pidx][nx][ny] = nxt;
                pq.push({nx, ny, nxt});
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        cin >> w >> c;

        int cnt = 0;
        for (int i = 1; i <= w; i++) {
            string s;
            cin >> s;
            s = "." + s + ".";
            for (int j = 0; j <= c + 1; j++) {
                graph[i][j] = s[j];
                if (s[j] == '$') {
                    p[cnt++] = {i, j};
                }
            }
        }

        for (int i = 0; i <= w + 1; i++) {
            graph[0][i] = '.';
            graph[w + 1][i] = '.';
        }

        memset(door, 0xf, sizeof(door));
        dijkstra(0, 0, 0);
        dijkstra(1, p[0].first, p[0].second);
        dijkstra(2, p[1].first, p[1].second);

        int ans = 1e9;
        for (int i = 0; i < w + 1; i++) {
            for (int j = 0; j < c + 1; j++) {
                if (graph[i][j] == '*')
                    continue;

                int sum = door[0][i][j] + door[1][i][j] + door[2][i][j];
                if (graph[i][j] == '#')
                    sum -= 2;

                ans = min(ans, sum);
            }
        }

        cout << ans << '\n';
    }
}
