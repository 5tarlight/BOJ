#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        int time[n + 1];
        for (int i = 1; i <= n; i++)
            cin >> time[i];
        vector<int> graph[n + 1];
        int pre[n + 1];

        fill(pre, pre + n + 1, 0);

        while (k--) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            pre[b]++;
        }

        int w;
        cin >> w;
        queue<int> q;
        int result[n + 1];
        fill(result, result + n + 1, 0);

        for (int i = 1; i <= n; i++)
            if (pre[i] == 0)
                q.push(i);

        while (pre[w] > 0) {
            int c = q.front();
            q.pop();

            for (int nxt : graph[c]) {
                result[nxt] = max(result[nxt], result[c] + time[c]);
                pre[nxt]--;

                if (pre[nxt] == 0)
                    q.push(nxt);
            }
        }

        cout << result[w] + time[w] << '\n';
    }
}
