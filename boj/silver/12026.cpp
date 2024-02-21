#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    string s;
    cin >> s;
    int dp[n];
    fill(dp, dp + n, 2000001);
    dp[0] = 0;
    queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int i = q.front();
        q.pop();
        char cur = s[i];

        char nxt;
        if (cur == 'B')
            nxt = 'O';
        else if (cur == 'O')
            nxt = 'J';
        else
            nxt = 'B';
        for (int j = i + 1; j < n; j++) {
            if (s[j] == nxt) {
                int d = j - i;
                if (d * d + dp[i] < dp[j]) {
                    dp[j] = d * d + dp[i];
                    q.push(j);
                }
            }
        }
    }

    if (dp[n - 1] > 1000000)
        cout << -1;
    else
        cout << dp[n - 1];
}
