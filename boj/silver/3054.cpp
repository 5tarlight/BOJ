#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();
    int w = 5, h = 4 * n + 1;
    char ans[w][h];
    memset(ans, '.', sizeof(ans));

    for (int i = 0; i < n; i++) {
        int x = 2, y = 2 + 4 * i;
        char t = i % 3 == 2 ? '*' : '#';

        ans[x][y] = s[i];
        ans[x + 1][y - 1] = t;
        ans[x + 1][y + 1] = t;
        ans[x + 2][y] = t;
        ans[x - 2][y] = t;
        ans[x - 1][y - 1] = t;
        ans[x - 1][y + 1] = t;

        if (t == '#' && ans[x][y - 2] == '.') ans[x][y - 2] = t;
        else if (t == '*') ans[x][y - 2] = t;

        if (t == '#' && ans[x][y + 2] == '.') ans[x][y + 2] = t;
        else if (t == '*') ans[x][y + 2] = t;
    }

    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++)
            cout << ans[i][j];
        cout << '\n';
    }
}
