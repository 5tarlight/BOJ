#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int n;
int a[15][15];
int dp[15][1 << 16][10];

int dfs(int x, int bit, int p) {
    if (dp[x][bit][p] != -1) return dp[x][bit][p];

    for (int i = 0; i < n; i++) {
        if (bit & (1 << i)) continue;
        if (a[x][i] < p) continue;

        int tmp = dfs(i, bit | (1 << i), a[x][i]) + 1;
        dp[x][bit][p] = max(dp[x][bit][p], tmp);
    }

    if (dp[x][bit][p] == -1) dp[x][bit][p] = 1;
    return dp[x][bit][p];
}

int main() {
    fio();

    cin >> n;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++) {
            a[i][j] = s[j] - '0';
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 1, 0);
}
