#include <bits/stdc++.h>
using namespace std;

void fio() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
}

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int main() {
    fio();

    int h, w, r, c, d;
    cin >> h >> w >> r >> c >> d;

    vector<string> a(h), b(h);
    for (int i = 0; i < h; i++) cin >> a[i];
    for (int i = 0; i < h; i++) cin >> b[i];

    vector<vector<int>> cleaned(h, vector<int>(w, 0));
    vector<vector<vector<bool>>> visited(h, vector<vector<bool>>(w, vector<bool>(4, false)));

    queue<tuple<int, int, int, int, int>> q;
    q.push({r, c, d, 0, 0});

    while (!q.empty()) {
        auto [y, x, dir, t, cycle] = q.front();
        q.pop();

        if (cleaned[y][x] == 0) {
            cleaned[y][x] = 1;
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    for (int k = 0; k < 4; k++) {
                        visited[i][j][k] = false;
                    }
                }
            }

            int rot = a[y][x] - '0';
            int ndir = (dir + rot) % 4;
            int ny = y + dr[ndir], nx = x + dc[ndir];

            if (ny < 0 || ny >= h || nx < 0 || nx >= w) {
                cout << t + 1 << "\n";
                return 0;
            }

            q.push({ny, nx, ndir, t + 1, 0});
        } else {
            if (visited[y][x][dir]) {
                cout << t - cycle << "\n";
                return 0;
            }
            visited[y][x][dir] = true;

            int rot = b[y][x] - '0';
            int ndir = (dir + rot) % 4;
            int ny = y + dr[ndir], nx = x + dc[ndir];

            if (ny < 0 || ny >= h || nx < 0 || nx >= w) {
                cout << t - cycle << "\n";
                return 0;
            }

            q.push({ny, nx, ndir, t + 1, cycle + 1});
        }
    }

    return 0;
}