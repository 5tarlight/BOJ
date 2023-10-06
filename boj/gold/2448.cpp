#include <iostream>
#include <algorithm>

using namespace std;

int n;
char map[3100][6200];

void draw(int x, int y, int k) {
    if (k == 3) {
        map[x][y] = '*';
        map[x + 1][y - 1] = '*';
        map[x + 1][y + 1] = '*';
        for (int j = y - 2; j <= y + 2; j++)
            map[x + 2][j] = '*';

        return;
    }

    draw(x, y, k / 2);
    draw(x + k / 2, y - k / 2, k / 2);
    draw(x + k / 2, y + k / 2, k / 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        fill(map[i], map[i] + 2 * n, ' ');
    }

    draw(0, n - 1, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n; j++)
            cout << map[i][j];
        cout << '\n';
    }
}
