#include <iostream>
#include <queue>

using namespace std;

int N, M;
int check[101][101];
int visited[101][101];
char map[101][101];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void bfs(int a, int b) {
    visited[a][b] = 1;

    queue<pair<int, int> > q;
    q.emplace(a, b);

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                if (map[nx][ny] == '1' && visited[nx][ny] == 0) {
                    check[nx][ny] = check[x][y] + 1;
                    visited[nx][ny] = 1;
                    q.emplace(nx, ny);
                }
            }
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> map[i];

    bfs(0, 0);
    cout << check[N - 1][M - 1] + 1;
}