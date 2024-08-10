#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

string graph[11];
int dp[11][1025];

bool canSit(string& row, int bit) {
    for (int i = 0; i < row.size(); i++)
        if (row[i] == 'x' && (bit & (1 << i)))
            return false;
    return true;
}

bool checkNear(int bit, int w) {
    for (int i = 0; i < w - 1; i++) {
        int tmp = 3 << i;
        if ((bit & tmp) == tmp) return false;
    }
    return true;
}

bool check(int bit, int front, int w) {
    for (int i = 0; i < w; i++) {
        if((1 << i) & front) {
            if (i > 0 && ((1 << (i - 1)) & bit)) return false;
            if ((1 << (i + 1) & bit)) return false;
        }
    }
    return true;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        memset(dp, 0, sizeof(dp));
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cin >> graph[i];

        vector<pair<int, int>> bs;

        for (int bit = 0; bit < (1 << m); bit++) {
            if (checkNear(bit, m)) {
                int cnt = 0;
                for (int i = 0; i < m; i++)
                    if ((1 << i) & bit) cnt++;
                bs.push_back({ bit, cnt });
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (auto& [bit, cnt] : bs) {
                if (!canSit(graph[i], bit)) continue;

                for (auto& [fbit, fcnt] : bs) {
                    if (check(bit, fbit, m)) {
                        dp[i][bit] = max(dp[i][bit], dp[i - 1][fbit] + cnt);
                        ans = max(ans, dp[i][bit]);
                    }
                }
            }
        }

        cout << ans << '\n';
    }
}
