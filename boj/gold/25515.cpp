#include <iostream>
#include <vector>

using namespace std;

int a[100000];
vector<int> graph[100000];
bool visited[100000];
int n;

long long dfs(int x) {
    long long nxt = a[x];

    for (auto v : graph[x]) {
        if (visited[v]) continue;

        visited[v] = true;
        long long target = dfs(v);
        if (target > 0)
            nxt += target;
    }

    return nxt;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 0; i < n; i++)
        cin >> a[i];

    visited[0] = true;
    cout << dfs(0);
}
