#include "bits/stdc++.h"

using namespace std;

int N, M;
vector<vector<char>> board;
vector<vector<int>> dp;
vector<vector<bool>> visited;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int dfs(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= M || board[x][y] == 'H') {
        return 0;
    }

    if (visited[x][y]) {
        cout << -1 << endl;
        exit(0);
    }

    if (dp[x][y] != -1) {
        return dp[x][y];
    }

    visited[x][y] = true;
    int moves = 0;
    int step = board[x][y] - '0';

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i] * step;
        int ny = y + dy[i] * step;
        moves = max(moves, 1 + dfs(nx, ny));
    }

    visited[x][y] = false;
    dp[x][y] = moves;
    return moves;
}

int main() {
    cin >> N >> M;
    board = vector(N, vector<char>(M));
    dp = vector(N, vector(M, -1));
    visited = vector(N, vector(M, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    cout << dfs(0, 0);
    return 0;
}
