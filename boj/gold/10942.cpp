#include <iostream>
#include <cstring>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    bool dp[n][n];
    memset(dp, false, sizeof(dp));

    for (int i = 0; i < n; i++)
        dp[i][i] = true;
    for (int i = 0; i < n - 1; i++)
        dp[i][i + 1] = a[i] == a[i + 1];
    for (int gap = 2; gap < n; gap++)
        for (int i = 0; i + gap < n; i++)
            dp[i][i + gap] = a[i] == a[i + gap] && dp[i + 1][i + gap - 1];

    int m;
    cin >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        cout << (int)dp[--a][--b] << '\n';
    }
}
