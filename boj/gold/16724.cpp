#include <iostream>

using namespace std;

int n, m;
char graph[1001][1000];
int parent[1000][1000];

void dfs(int x, int y, int p) {
    if (parent[x][y] == p && x * m + y != p)
        return;

    parent[x][y] = p;

    if (x > 0 && graph[x - 1][y] == 'D') {
        dfs(x - 1, y, p);
    }
    if (x < n - 1 && graph[x + 1][y] == 'U') {
        dfs(x + 1, y, p);
    }
    if (y > 0 && graph[x][y - 1] == 'R') {
        dfs(x, y - 1, p);
    }
    if (y < m - 1 && graph[x][y + 1] == 'L') {
        dfs(x, y + 1, p);
    }
}

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << parent[i][j] << " ";
        cout << endl;
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> graph[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            parent[i][j] = i * m + j;
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (parent[i][j] == i * m + j)
                dfs(i, j, i * m + j);

    int count = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (parent[i][j] == i * m + j)
                count++;

    cout << count;
}
