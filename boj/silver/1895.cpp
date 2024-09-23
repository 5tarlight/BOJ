#include "bits/stdc++.h"

using namespace std;

int r, c, t;
int graph[40][40];
int ans;

void check(int x, int y) {
    vector<int> a;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            a.push_back(graph[x + i][y + j]);

    sort(a.begin(), a.end());

    if (a[4] >= t)
        ans++;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> r >> c;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> graph[i][j];
    cin >> t;

    for (int i = 0; i < r - 2; i++)
        for (int j = 0; j < c - 2; j++)
            check(i, j);

    cout << ans;
}
