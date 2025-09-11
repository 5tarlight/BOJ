#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

long long dp[21][21][21];

int ddp(int a, int b, int c) {
    if (dp[a][b][c] != -1) return dp[a][b][c];
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    if (a < b && b < c) {
        dp[a][b][c] = ddp(a, b, c - 1) + ddp(a, b - 1, c - 1) - ddp(a, b - 1, c);
    } else {
        dp[a][b][c] = ddp(a - 1, b, c) + ddp(a - 1, b - 1, c) + ddp(a - 1, b, c - 1) - ddp(a - 1, b - 1, c - 1);
    }

    return dp[a][b][c];
}

int main() {
    fio();

    memset(dp, -1, sizeof(dp));

    for (int i = 0; i <= 20; i++) {
        dp[i][0][0] = 1;
        dp[0][i][0] = 1;
        dp[0][0][i] = 1;
    }

    while (true) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) break;

        int res;
        if (a <= 0 || b <= 0 || c <= 0) {
            res = 1;
        } else if (a > 20 || b > 20 || c > 20) {
            res = ddp(20, 20, 20);
        } else {
            res = ddp(a, b, c);
        }
        cout << "w(" << a << ", " << b << ", " << c << ") = " << res << "\n";
    }
}
