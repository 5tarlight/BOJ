#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

const int INF = 1e9;
int arr[100001];
int dp[100001][5][5];

int cost(int from, int to) {
    if (from == 0) return 2;
    if (from == to) return 1;
    if ((from == 1 && to == 3) || (from == 3 && to == 1)) return 4;
    if ((from == 2 && to == 4) || (from == 4 && to == 2)) return 4;
    return 3;
}

int main() {
    fio();

    int n = 0, x;
    while (cin >> x && x != 0)
        arr[n++] = x;

    for (int i = 0; i <= n; ++i)
        for (int j = 0; j < 5; ++j)
            for (int k = 0; k < 5; ++k)
                dp[i][j][k] = INF;

    dp[0][0][0] = 0;
    for (int i = 0; i < n; ++i) {
        int next = arr[i];
        for (int l = 0; l < 5; ++l) {
            for (int r = 0; r < 5; ++r) {
                if (dp[i][l][r] == INF) continue;

                dp[i+1][next][r] = min(dp[i+1][next][r], dp[i][l][r] + cost(l, next));
                dp[i+1][l][next] = min(dp[i+1][l][next], dp[i][l][r] + cost(r, next));
            }
        }
    }

    int ans = INF;
    for (int l = 0; l < 5; ++l)
        for (int r = 0; r < 5; ++r)
            ans = min(ans, dp[n][l][r]);

    cout << ans;
}
