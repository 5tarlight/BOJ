#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

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
        int k;
        cin >> k;
        int a[k];
        for (int i = 0; i < k; i++)
            cin >> a[i];

        for (int i = 0; i < k - 1; i++) {
            for (int j = i + 1; j < k; j++) {
                graph[a[i]].push_back(a[j]);
                depth[a[j]]++;
            }
        }
    }

    queue<int> q;
    vector<int> ans;
    for (int i = 1; i <= n; i++)
        if (depth[i] == 0)
            q.push(i);

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        ans.push_back(x);

        for (int v : graph[x]) {
            depth[v]--;
            if (depth[v] == 0)
                q.push(v);
        }
    }

    if (ans.size() != n)
        cout << 0;
    else
        for (int v : ans)
            cout << v << '\n';
}
