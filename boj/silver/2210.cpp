#include <iostream>
#include <set>

using namespace std;

int graph[5][5];
set<int> s;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void dfs(int x, int y, int d, int n) {
    if (d == 5) {
        s.insert(n);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
            continue;

        dfs(nx, ny, d + 1, 10 * n + graph[nx][ny]);
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> graph[i][j];

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            dfs(i, j, 0, graph[i][j]);

    cout << s.size();
}
