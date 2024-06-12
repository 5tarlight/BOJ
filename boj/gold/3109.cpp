#include <iostream>
#include <string>

using namespace std;

int dx[] = { -1, 0, 1 };
int r, c;
int ans;
int graph[10000][500];

bool dfs(int x,int y) {
    graph[x][y] = 1;
    if (y == c - 1) {
        ans++;
        return true;
    }

    for (int i = 0; i < 3; i++)
        if (x + dx[i] >= 0 && x + dx[i] < r && graph[x + dx[i]][y + 1] == 0)
            if (dfs(x + dx[i], y + 1))
                return true;

    return false;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < c; j++) {
            if (s[j] == '.')
                graph[i][j] = 0;
            else
                graph[i][j] = 1;
        }
    }

    for (int i = 0; i < r; i++)
        dfs(i, 0);

    cout << ans;
}
