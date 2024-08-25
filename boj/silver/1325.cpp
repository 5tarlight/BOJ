#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    bool visited[n + 1];
    vector<int> graph[n + 1];

    while (m--) {
        int a, b;
        cin >> a >> b;
        graph[b].push_back(a);
    }

    int cnt = 0;
    vector<int> ans;

    for (int s = 1; s <= n; s++) {
        fill(visited, visited + n + 1, false);
        queue<int> q;
        q.push(s);
        visited[s] = true;

        int c = 1;
        while (!q.empty()) {
            int x = q.front();
            q.pop();

            for (int nxt : graph[x]) {
                if (visited[nxt]) continue;

                visited[nxt] = true;
                c++;
                q.push(nxt);
            }
        }

        if (c > cnt) {
            cnt = c;
            ans.clear();
            ans.push_back(s);
        } else if (c == cnt)
            ans.push_back(s);
    }

    for (int v : ans)
        cout << v << ' ';
}
