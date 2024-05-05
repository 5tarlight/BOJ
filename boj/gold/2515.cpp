#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, s;
    cin >> n >> s;
    pair<int, int> a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a, a + n);

    int dp[n];
    int idx = 0;
    for (int i = 0; i < n; i++) {
        while (idx < i && a[i].first - a[idx].first >= s)
            idx++;
        dp[i] = a[i].second + (idx ? dp[idx - 1] : 0);
        if (i)
            dp[i] = max(dp[i], dp[i - 1]);
    }

    cout << dp[n - 1];
}
