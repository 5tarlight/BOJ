#include <iostream>
#include <algorithm>

using namespace std;

int graph[10][10];
bool visited[10];
int n;
int ans = 1e9;

void backtrack(int s, int x, int d, int cost) {
    if (d == n) {
        if (graph[x][s] == 0)
            return;
        ans = min(ans, cost + graph[x][s]);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (graph[x][i] == 0 || visited[i])
            continue;

        visited[i] = true;
        backtrack(s, i, d + 1, cost + graph[x][i]);
        visited[i] = false;
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

    for (int i = 0; i < n; i++) {
        visited[i] = true;
        backtrack(i, i, 1, 0);
        visited[i] = false;
    }

    cout << ans;
}
