#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bool graph[n + 1][n + 1];
        int deg[n + 1];
        fill(deg, deg + n + 1, 0);
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            fill(graph[i + 1], graph[i + 1] + n + 1, false);
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                graph[a[i]][a[j]] = true;
                deg[a[j]]++;
            }
        }

        int m;
        cin >> m;
        while (m--) {
            int a, b;
            cin >> a >> b;

            if (graph[a][b]) {
                graph[a][b] = false;
                graph[b][a] = true;
                deg[a]++;
                deg[b]--;
            } else {
                graph[b][a] = false;
                graph[a][b] = true;
                deg[b]++;
                deg[a]--;
            }
        }

        queue<int> q;
        vector<int> ans;
        for (int i = 1; i <= n; i++)
            if (deg[i] == 0)
                q.push(i);

        for (int i = 1; i <= n; i++) {
            if (q.empty()) {
                cout << "IMPOSSIBLE\n";
                break;
            } else if (q.size() > 1) {
                cout << "?\n";
                break;
            }

            int cur = q.front();
            q.pop();
            ans.push_back(cur);

            for (int j = 1; j <= n; j++) {
                if (graph[cur][j]) {
                    deg[j]--;

                    if (deg[j] == 0)
                        q.push(j);
                }
            }
        }

        if (ans.size() == n) {
            for (auto v : ans) {
                cout << v << ' ';
            }
            cout << '\n';
        }
    }
}
