#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int r, c;
    cin >> r >> c;
    char g[r][c + 1];
    for (int i = 0; i < r; i++) {
        cin >> g[i];
    }

    bool used[r][c][2];
    memset(used, 0, sizeof(used));

    vector<string> ans;
    // Horizontal
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (used[i][j][0] || g[i][j] == '#') continue;

            used[i][j][0] = true;
            string tmp = string(1, g[i][j]);
            for (int k = j + 1; k < c; k++) {
                if (g[i][k] == '#') break;
                used[i][k][0] = true;
                tmp += g[i][k];
            }
            if (tmp.size() >= 2)
                ans.push_back(tmp);
        }
    }

    // Vertical
    for (int j = 0; j < c; j++) {
        for (int i = 0; i < r; i++) {
            if (used[i][j][1] || g[i][j] == '#') continue;

            used[i][j][1] = true;
            string tmp = string(1, g[i][j]);
            for (int k = i + 1; k < r; k++) {
                if (g[k][j] == '#') break;
                used[k][j][1] = true;
                tmp += g[k][j];
            }
            if (tmp.size() >= 2)
                ans.push_back(tmp);
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans.front();
}
