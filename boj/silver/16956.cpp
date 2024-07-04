#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int r, c;
    cin >> r >> c;
    char graph[r][c + 1];
    bool hasWolf = false;
    for (int i = 0; i < r; i++) {
        cin >> graph[i];

        for (int j = 0; j < c; j++)
            if (graph[i][j] == 'W')
                hasWolf = true;
    }

    if (!hasWolf) {
        cout << "1\n";
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++)
                cout << graph[i][j];
            cout << '\n';
        }
        return 0;
    }

    int dx[] = { -1, 1, 0, 0 };
    int dy[] = { 0, 0, -1, 1 };
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (graph[i][j] != 'S')
                continue;

            for (int k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];

                if (x < 0 || y < 0 || x >= r || y >= c)
                    continue;

                if (graph[x][y] == 'W') {
                    cout << 0;
                    return 0;
                } else if (graph[x][y] == '.')
                    graph[x][y] = 'D';
            }
        }
    }

    cout << "1\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            cout << graph[i][j];
        cout << '\n';
    }
}
