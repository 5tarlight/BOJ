#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> tree[10'001];
int maxd;
int endp;
bool visited[10'001];

void dfs(int cur, int d) {
    if (d > maxd) {
        maxd = d;
        endp = cur;
    }

    for (auto &p : tree[cur]) {
        if (!visited[p.first]) {
            visited[p.first] = true;
            dfs(p.first, d + p.second);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        tree[a].push_back({b, c});
        tree[b].push_back({a, c});
    }

    visited[1] = true;
    dfs(1, 0);
    fill(visited, visited + n + 1, false);
    maxd = 0;
    visited[endp] = true;
    dfs(endp, 0);
    cout << maxd;
}
