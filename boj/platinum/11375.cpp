#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m;
vector<int> adj[1001];
bool visited[1001];
int work[1001];
int ans = 0;

bool dfs(int s) {
    visited[s] = true;

    for (int i = 0; i < adj[s].size(); i++) {
        int nxt = adj[s][i];

        if (work[nxt] == 0 || !visited[work[nxt]] && dfs(work[nxt])) {
            work[nxt] = s;
            return true;
        }
    }

    return false;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int nxt;
        cin >> nxt;
        for (int j = 0; j < nxt; j++) {
            int num;
            cin >> num;
            adj[i].push_back(num);
        }
    }

    for (int i = 1; i <= n; i++) {
        memset(visited, false, sizeof(visited));

        if (dfs(i))
            ans++;
    }

    cout << ans;
}
