#include <iostream>
#include <cmath>

using namespace std;

int graph[10][10];
int n;
bool diag1[20], diag2[20];
int ans = 0;

void backtrack(int s, int d) {
    if (s >= 2 * n - 1) {
        if (d > ans) {
            ans = d;
        }

        return;
    }

    bool placed = false;

    for (int j = 0; j < n - abs(s - n + 1); j++) {
        int x = n - 1 <= s ? n - 1 - j : s - j;
        int y = n - 1 <= s ? s - n + 1 + j : j;

        if (graph[x][y] == 1 && !diag1[s] && !diag2[n - 1 + x - y]) {
            placed = true;
            diag1[s] = diag2[n - 1 + x - y] = true;
            backtrack(s + 1, d + 1);
            diag1[s] = diag2[n - 1 + x - y] = false;
        }
    }

    if (!placed) {
        backtrack(s + 1, d);
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    backtrack(0, 0);

    cout << ans;
}
