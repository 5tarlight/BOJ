#include <iostream>
#include <algorithm>

using namespace std;

#define INF 0x3f3f3f3f

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int d[n + 1][n + 1];
    int nx[n + 1][n + 1];

    for (int i = 1; i <= n; i++)
        fill(d[i], d[i] + n + 1, INF);

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
        nx[a][b] = b;
    }

    for (int i = 1; i <= n; i++)
        d[i][i] = 0;

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    nx[i][j] = nx[i][k];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (d[i][j] == 0 || d[i][j] == INF)
                cout << "0 ";
            else
                cout << d[i][j] << ' ';
        }
        cout << '\n';
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (d[i][j] == 0 || d[i][j] == INF) {
                cout << "0\n";
                continue;
            }

            vector<int> path;
            int start = i;
            while (start != j) {
                path.push_back(start);
                start = nx[start][j];
            }
            path.push_back(j);

            cout << path.size() << ' ';
            for (auto &x: path)
                cout << x << ' ';
            cout << '\n';
        }
    }
}
