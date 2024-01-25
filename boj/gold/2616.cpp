#include <iostream>
#include <algorithm>

using namespace std;

int a[50001];
int dp[4][50001];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        a[i] = a[i - 1] + num;
    }
    int m;
    cin >> m;

    for (int i = 1; i <= 3; i++) {
        for (int j = i * m; j <= n; j++) {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - m] + a[j] - a[j - m]);
        }
    }

    cout << dp[3][n];
}
