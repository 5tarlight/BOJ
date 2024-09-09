#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m, q;
    cin >> n >> m >> q;
    bool graph[n][m];
    memset(graph, true, sizeof(graph));
    int cnt = n * m;

    while (q--) {
        int op;
        cin >> op;

        if (op == 1) {
            int dy, dx, y, x;
            cin >> dy >> dx >> y >> x;
            y--; x--;
            for (int i = 0;; i++) {
                int ny = y + dy * i;
                int nx = x + dx * i;

                if (ny < 0 || ny >= n || nx < 0 || nx >= m || !graph[ny][nx]) break;
                graph[ny][nx] = false;
                cnt--;
            }
        } else if (op == 2) {
            int y, x;
            cin >> y >> x;
            y--; x--;

            cout << !graph[y][x] << '\n';
        } else {
            cout << cnt << '\n';
        }
    }
}
