#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int arr[8][8];
int temp[8][8];
vector<pair<int, int>> virus;
int n, m;
int ans = 0;

void copy() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            temp[i][j] = arr[i][j];
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) {
                virus.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < n * m; i++) {
        for (int j = i + 1; j < n * m; j++) {
            for (int k = j + 1; k < n * m; k++) {
                if (arr[i / m][i % m] == 0 && arr[j / m][j % m] == 0 && arr[k / m][k % m] == 0) {
                    copy();
                    temp[i / m][i % m] = 1;
                    temp[j / m][j % m] = 1;
                    temp[k / m][k % m] = 1;
                    int cnt = 0;
                    queue<pair<int, int>> q;
                    for (auto v : virus) {
                        q.push(v);
                    }

                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        for (int l = 0; l < 4; l++) {
                            int nx = x + "1210"[l] - '1';
                            int ny = y + "2101"[l] - '1';

                            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                                continue;
                            }

                            if (temp[nx][ny] == 0) {
                                temp[nx][ny] = 2;
                                q.push({nx, ny});
                            }
                        }
                    }

                    for (int l = 0; l < n; l++) {
                        for (int o = 0; o < m; o++) {
                            if (temp[l][o] == 0) {
                                cnt++;
                            }
                        }
                    }
                    ans = max(ans, cnt);
                }
            }
        }
    }

    cout << ans << '\n';
}
