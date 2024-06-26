#include <iostream>
#include <queue>
#include <string>

using namespace std;

char graph[51][50];
bool visited[50][50][1 << 6];
int n, m;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
pair<int, int> start;

bool isUpper(char ch) {
    if (ch >= 'A' && ch <= 'Z') return true;
    else return false;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);


    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            graph[i][j] = s[j];

            if (s[j] == '0') {
                start = { i, j };
                graph[i][j] = '.';
            }
        }
    }

    queue<pair<pair<int, int>, pair<int, int>>> q; // {{ x, y }, { bit, cost }}
    q.push({ start, { 0, 0 }});
    visited[start.first][start.second][0] = true;

    while (!q.empty()) {
        auto [pos, data] = q.front();
        q.pop();
        auto [x, y] = pos;
        auto [bit, cost] = data;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (
                    nx < 0 || nx >= n || ny < 0 || ny >= m ||
                    graph[nx][ny] == '#'
            ) continue;

            if (graph[nx][ny] == '1') {
                cout << cost + 1;
                return 0;
            } else if (graph[nx][ny] == '.') {
                if (visited[nx][ny][bit]) continue;
                visited[nx][ny][bit] = true;
                q.push({{ nx, ny }, { bit, cost + 1 }});
            } else {
                if (isUpper(graph[nx][ny])) {
                    if (visited[nx][ny][bit]) continue;
                    int idx = graph[nx][ny] - 'A';
                    if (bit & (1 << idx)) {
                        visited[nx][ny][bit] = true;
                        q.push({{ nx, ny }, { bit, cost + 1 }});
                    }
                } else {
                    int idx = graph[nx][ny] - 'a';
                    int nxtBit = bit | (1 << idx);
                    if (visited[nx][ny][nxtBit]) continue;
                    visited[nx][ny][nxtBit] = true;
                    q.push({{ nx, ny }, { nxtBit, cost + 1 }});
                }
            }
        }
    }

    cout << -1;
}
