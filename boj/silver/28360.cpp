#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> graph[n + 1];
    double dp[n + 1];
    fill(dp, dp + n + 1, 0);
    dp[1] = 100;

    while (m--) {
        int a, b;
        cin >> a >> b;
        graph[min(a, b)].push_back(max(a, b));
    }

    vector<int> target;
    for (int i = 1; i <= n; i++) {
        if (graph[i].empty()) {
            target.push_back(i);
            continue;
        }

        sort(graph[i].begin(), graph[i].end());

        for (int nxt : graph[i])
            dp[nxt] += dp[i] / graph[i].size();
    }

    double ans = 0;
    for (int t : target) {
        if (dp[t] > ans) {
            ans = dp[t];
        }
    }

    cout << ans;
}
