#include <iostream>
#include <queue>

using namespace std;

int N, M;
int graph[101][101];
bool visited[101][101];
// W : 0
// B : 1

int bfs(int x, int y) {
    if (visited[x][y])
        return -1;

    int target = graph[x][y];
    queue<pair<int, int>> q;
    q.emplace(x, y);

    int count = 0;
    while(!q.empty()) {
        auto p = q.front();
        q.pop();
        int a = p.first;
        int b = p.second;

        if (a < 0 || a >= M || b < 0 || b >= N)
            continue;
        else if (graph[a][b] == target && !visited[a][b]) {
            count++;
            visited[a][b] = true;
            q.emplace(a - 1, b);
            q.emplace(a, b - 1);
            q.emplace(a + 1, b);
            q.emplace(a, b + 1);
        }
    }

    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        char line[N];
        cin >> line;

        for (int j = 0; j < N; j++) {
            if (line[j] == 'W')
                graph[i][j] = 0;
            else
                graph[i][j] = 1;
            visited[i][j] = false;
        }
    }

    int w = 0;
    int b = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            int exp = bfs(i, j);

            if (exp == -1)
                continue;
            else if (graph[i][j] == 0) { // W
                w += exp * exp;
            } else {
                b += exp * exp;
            }
        }
    }

    cout  << w << " " << b;
}
