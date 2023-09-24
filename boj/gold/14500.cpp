#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int graph[500][500];
int dxy[4][2] = {
    { 1,0 },
    { -1,0 },
    { 0,1 },
    { 0,-1 },
};
bool visited[500][500];
int answer;

bool check(int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= m)
        return false;
    else
        return true;
}

void dfs(int x, int y, int depth, int sum) {
    if (depth == 3) {
        answer = max(answer, sum);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dxy[i][0];
        int ny = y + dxy[i][1];
        if (!check(nx, ny) || visited[nx][ny])
            continue;

        visited[nx][ny] = true;
        dfs(nx, ny, depth + 1, sum + graph[nx][ny]);
        visited[nx][ny] = false;
    }
}

void shape1(int r, int c) {
    int sum = graph[r][c] + graph[r][c + 1] + graph[r][c + 2] + graph[r - 1][c + 1];
    answer = max(answer, sum);
}

void shape2(int r, int c) {
    int sum = graph[r][c] + graph[r][c + 1] + graph[r][c + 2] + graph[r + 1][c + 1];
    answer = max(answer, sum);
}

void shape3(int r, int c) {
    int sum = graph[r][c] + graph[r + 1][c] + graph[r + 2][c] + graph[r + 1][c + 1];
    answer = max(answer, sum);
}

void shape4(int r, int c) {
    int sum = graph[r][c] + graph[r - 1][c + 1] + graph[r][c + 1] + graph[r + 1][c + 1];
    answer = max(answer, sum);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    answer = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = true;
            dfs(i, j, 0, graph[i][j]);
            visited[i][j] = false;
            if (i - 1 >= 0 && j + 2 < m)
                shape1(i, j);
            if (j + 2 < m && i + 1 < n)
                shape2(i, j);
            if (i + 2 < n && j + 1 < m)
                shape3(i, j);
            if (i + 1 < n && i - 1 >= 0 && j + 1 < m)
                shape4(i, j);
        }
    }

    cout << answer;
}
