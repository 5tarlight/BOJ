#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int r, c;
    cin >> r >> c;
    int graph[r][c];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> graph[i][j];
    int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
    int dy[] = { 1, 1, 0, -1, -1, -1, 0, 1 };

    long long ans = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (graph[i][j] > ans) {
                int temp = graph[i][j];
                int x = i, y = j;
                bool adj = false;

                for (int k = 0; k < 8; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
                        if (graph[nx][ny] == temp) {
                            adj = true;
                            break;
                        }
                    }
                }

                if (adj) {
                    ans = temp;
                }
            }
        }
    }

    cout << ans;
}
