#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

char graph[100][101];
int n, m;

bool check(int x, int y) {
    if (x + 3 < n || y + 3 < m) return false;

    for (int i = x; i < x + 3; i++)
        for (int j = y; j < y + 3; j++)
            if (graph[i][j] == 'x') return false;
    return true;
}

int main() {
    fio();

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            cin >> graph[i];

        bool isSewon = true;
        while (true) {
            bool found = false;
            for (int i = 0; i < n && !found; i++) {
                for (int j = 0; j < m; j++) {
                    if (check(i, j)) {
                        for (int x = i; x < i + 3; x++)
                            for (int y = j; y < j + 3; y++)
                                graph[i][j] = 'x';
                        found = true;
                        break;
                    }
                }
            }

            if (found) {
                isSewon = !isSewon;
                continue;
            }

            for (int i = 0; i < n && !found; i++) {
                for (int j = 0; j < m; j++) {
                    if (graph[i][j] == '.') {
                        graph[i][j] = 'x';
                        found = true;
                        break;
                    }
                }
            }

            if (found) {
                isSewon = !isSewon;
                continue;
            } else {
                if (isSewon) cout << "pizza\n";
                else cout << "sewon\n";
                break;
            }
        }
    }
}
