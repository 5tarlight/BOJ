#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, 1, -1};

int main() {
    fio();

    int r, c, m;
    cin >> r >> c >> m;
    vector<vector<pair<pair<int, int>, int>>> shark(r, vector<pair<pair<int, int>, int>>(c, {{0, 0}, 0}));

    while (m--) {
        int x, y, s, d, z;
        cin >> x >> y >> s >> d >> z;
        x--, y--;
        shark[x][y] = {{s, d}, z};
    }

    int ans = 0;

    for (int fisher = 0; fisher < c; fisher++) {
        // Catch the shark
        for (int i = 0; i < r; i++) {
            if (shark[i][fisher].second > 0) {
                ans += shark[i][fisher].second;
                shark[i][fisher] = {{0, 0}, 0};
                break;
            }
        }

        // Move sharks
        vector<vector<pair<pair<int, int>, int>>> new_shark(r, vector<pair<pair<int, int>, int>>(c, {{0, 0}, 0}));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (shark[i][j].second == 0) continue;

                int s = shark[i][j].first.first;
                int d = shark[i][j].first.second;
                int z = shark[i][j].second;

                int x = i, y = j;

                int cycle = (d == 1 || d == 2) ? 2 * (r - 1) : 2 * (c - 1);
                if (cycle != 0) s %= cycle;

                while (s--) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
                        if (d == 1) d = 2;
                        else if (d == 2) d = 1;
                        else if (d == 3) d = 4;
                        else if (d == 4) d = 3;
                        nx = x + dx[d];
                        ny = y + dy[d];
                    }

                    x = nx;
                    y = ny;
                }

                if (new_shark[x][y].second < z) {
                    new_shark[x][y] = {{shark[i][j].first.first, d}, z};
                }
            }
        }

        shark = new_shark;
    }

    cout << ans << '\n';
}
