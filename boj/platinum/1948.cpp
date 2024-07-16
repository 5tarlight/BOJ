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
    vector<pair<int, int>> graph[n + 1];
    vector<pair<int, int>> rev[n + 1];
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ b, c });
        rev[b].push_back({ a, c });
    }
    int s, e;
    cin >> s >> e;

    queue<int> q;
    q.push(s);
    int time[n + 1];
    fill(time, time + n + 1, -1);
    time[s] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (auto p : graph[x]) {
            auto [nxt, cost] = p;
            if (time[nxt] < time[x] + cost) {
                time[nxt] = time[x] + cost;
                q.push(nxt);
            }
        }
    }

    queue<pair<int, int>> qq;
    bool visited[n + 1];
    fill(visited, visited + n + 1, false);
    qq.push({ e, 0 });
    visited[e] = false;
    int road = 0;
    while (!qq.empty()) {
        auto [x, cur] = qq.front();
        qq.pop();

        for (auto [nxt, cost] : rev[x]) {
            int nxtTime = cur + cost;
            if (time[e] - nxtTime == time[nxt]) {
                road++;
                if (!visited[nxt]) {
                    qq.push({ nxt, nxtTime });
                    visited[nxt] = true;
                }
            }
        }
    }

    cout << time[e] << '\n' << road;
}
