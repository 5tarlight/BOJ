#include <iostream>

using namespace std;

int dist[10][10];
int n, k;
int ans = 1e9;
bool visited[10];

void backtrack(int idx, int d, int cost) {
    if (d == n) {
        if (cost < ans)
            ans = cost;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (visited[i])
            continue;

        visited[i] = true;
        backtrack(i, d + 1, cost + dist[idx][i]);
        visited[i] = false;
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> dist[i][j];

    for (int p = 0; p < n; p++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][j] > dist[i][p] + dist[p][j])
                    dist[i][j] = dist[i][p] + dist[p][j];

    backtrack(k, 0, 0);

    cout << ans;
}
