#include <iostream>
#include <algorithm>

using namespace std;

int graph[10][10];
int n;
bool visited[10][10];
int ans = 1e9;

bool canPlant(int x, int y) {
    if (x == 0 || x == n - 1 || y == 0 || y == n - 1) return false;
    if (
            visited[x][y] ||
            visited[x - 1][y] ||
            visited[x + 1][y] ||
            visited[x][y - 1] ||
            visited[x][y + 1]
        ) return false;
    return true;
}

void mark(int x, int y, bool v) {
    visited[x][y] = v;
    visited[x - 1][y] = v;
    visited[x + 1][y] = v;
    visited[x][y - 1] = v;
    visited[x][y + 1] = v;
}

int getPrice(int x, int y) {
    return graph[x][y] + graph[x - 1][y] + graph[x + 1][y] + graph[x][y - 1] + graph[x][y + 1];
}

void backtrack(int x, int y, int d, int sum) {
    if (d == 3) {
        ans = min(ans, sum);
        return;
    }

    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (visited[i][j]) continue;

            if (canPlant(i, j)) {
                mark(i, j, true);
                backtrack(i, j, d + 1, sum + getPrice(i, j));
                mark(i, j, false);
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    backtrack(0, 0, 0, 0);

    cout << ans;
}
