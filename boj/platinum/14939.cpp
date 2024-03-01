#include <iostream>
#include <algorithm>
#include <string>

#define INF 1e9

using namespace std;

bool arr[10][10];
bool temp[10][10];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
int ans = INF;

bool isOut(int x, int y) {
    if (x < 0 || x >= 10 || y < 0 || y >= 10)
        return true;
    else
        return false;
}

void toggle(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (!isOut(nx, ny))
            temp[nx][ny] = !temp[nx][ny];
    }

    temp[x][y] = !temp[x][y];
}

void clone() {
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            temp[i][j] = arr[i][j];
}

bool check() {
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            if (temp[i][j])
                return false;
    return true;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    for (int i = 0; i < 10; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < 10; j++) {
            char c = s[j];
            if (c == 'O')
                arr[i][j] = true;
        }
    }

    for (int step = 0; step < (1 << 10); step++) {
        int cnt = 0;
        clone();

        // 1st line
        for (int bit = 0; bit < 10; bit++) {
            if (step & (1 << bit)) {
                cnt++;
                toggle(0, bit);
            }
        }

        // rest
        for (int x = 1; x < 10; x++) {
            for (int y = 0; y < 10; y++) {
                if (temp[x - 1][y]) {
                    toggle(x, y);
                    cnt++;
                }
            }
        }

        if (check())
            ans = min(cnt, ans);
    }

    if (ans == INF)
        cout << -1;
    else
        cout << ans;
}
