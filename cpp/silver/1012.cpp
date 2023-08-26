#include <iostream>

using namespace std;

int graph[50][50];

bool dfs(int N, int M, int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= M)
        return false;

    if (graph[x][y] == 1) {
        graph[x][y] = 0;

        dfs(N, M, x - 1, y);
        dfs(N, M, x, y - 1);
        dfs(N, M, x + 1, y);
        dfs(N, M, x, y + 1);

        return true;
    } else {
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    for (int _ = 0; _ < T; _++) {
        for (int i = 0; i < 50; i++) {
            for (int j = 0; j < 50; j++) {
                graph[i][j] = 0;
            }
        }

        int M, N, K;

        cin >> M >> N >> K;

        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y;
            graph[y][x] = 1;
        }

        int result = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (dfs(N, M, i, j))
                    result++;
            }
        }

        cout << result << '\n';
    }
}
