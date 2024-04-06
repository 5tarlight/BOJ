#include <iostream>

using namespace std;

int n;
long long graph[6][20][20];
long long ans = 2;

void getMax() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (ans < graph[5][i][j])
                ans = graph[5][i][j];
}

void reset(int d) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[d][i][j] = 0;
}

void merge(int d, int dir) {
    reset(d);

    // U R D L
    if (dir == 1) {
        for (int j = 0; j < n; j++) {
            int idx = 0;
            for (int i = 0; i < n; i++) {
                if (graph[d - 1][i][j] == 0)
                    continue;

                if (graph[d][idx][j] == 0)
                    graph[d][idx][j] = graph[d - 1][i][j];
                else if (graph[d][idx][j] == graph[d - 1][i][j]) {
                    graph[d][idx][j] *= 2;
                    idx++;
                } else {
                    idx++;
                    graph[d][idx][j] = graph[d - 1][i][j];
                }
            }
        }
    } else if (dir == 2) {
        for (int i = 0; i < n; i++) {
            int idx = n - 1;
            for (int j = n - 1; j >= 0; j--) {
                if (graph[d - 1][i][j] == 0)
                    continue;

                if (graph[d][i][idx] == 0)
                    graph[d][i][idx] = graph[d - 1][i][j];
                else if (graph[d][i][idx] == graph[d - 1][i][j]) {
                    graph[d][i][idx] *= 2;
                    idx--;
                } else {
                    idx--;
                    graph[d][i][idx] = graph[d - 1][i][j];
                }
            }
        }
    } else if (dir == 3) {
        for (int j = 0; j < n; j++) {
            int idx = n - 1;
            for (int i = n - 1; i >= 0; i--) {
                if (graph[d - 1][i][j] == 0)
                    continue;

                if (graph[d][idx][j] == 0)
                    graph[d][idx][j] = graph[d - 1][i][j];
                else if (graph[d][idx][j] == graph[d - 1][i][j]) {
                    graph[d][idx][j] *= 2;
                    idx--;
                } else {
                    idx--;
                    graph[d][idx][j] = graph[d - 1][i][j];
                }
            }
        }
    } else if (dir == 4) {
        for (int i = 0; i < n; i++) {
            int idx = 0;
            for (int j = 0; j < n; j++) {
                if (graph[d - 1][i][j] == 0)
                    continue;

                if (graph[d][i][idx] == 0)
                    graph[d][i][idx] = graph[d - 1][i][j];
                else if (graph[d][i][idx] == graph[d - 1][i][j]) {
                    graph[d][i][idx] *= 2;
                    idx++;
                } else {
                    idx++;
                    graph[d][i][idx] = graph[d - 1][i][j];
                }
            }
        }
    }
}

void backtrack(int d) {
    if (d == 5) {
        getMax();
        return;
    }

    for (int i = 0; i < 4; i++) {
        merge(d + 1, i + 1);
        backtrack(d + 1);
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[0][i][j];

    backtrack(0);
    cout << ans;
}
