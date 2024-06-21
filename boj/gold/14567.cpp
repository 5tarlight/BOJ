#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int depth[n + 1];
    fill(depth, depth + n + 1, 0);
    vector<int> graph[n + 1];
    while (m--) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        depth[b]++;
    }

    int ans[n + 1];
    fill(ans, ans + n + 1, 0);
    queue<int> q;

    for (int i = 1; i <= n; i++)
        if (depth[i] == 0)
            q.push(i);

    int level = 1;
    int size = q.size();
    while (!q.empty()) {
        if (size == 0) {
            level++;
            size = q.size();
        }

        int x = q.front();
        q.pop();
        ans[x] = level;
        size--;

        for (int nxt : graph[x]) {
            depth[nxt]--;
            if (depth[nxt] == 0)
                q.push(nxt);
        }
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
}
