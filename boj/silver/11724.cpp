#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool visited[1001];
vector<int> graph[1001];

void dfs(int x) {
    for (int y : graph[x]) {
        if (!visited[y]) {
            visited[y] = true;
            dfs(y);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            cnt++;
            dfs(i);
        }
    }

    cout << cnt;
}