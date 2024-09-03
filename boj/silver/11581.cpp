#include "bits/stdc++.h"

using namespace std;

int n;
bool ok = true;
bool visited[101];
bool done[101];
vector<int> adj[101];

void dfs(int x) {
    visited[x] = true;
    for (int v : adj[x]) {
        if (done[v]) return;
        else if (visited[v]) ok = false;
        else dfs(v);
    }
    done[x] = true;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i <= n - 1; i++) {
        int m;
        cin >> m;
        while (m--) {
            int c;
            cin >> c;
            adj[i].push_back(c);
        }
    }

    dfs(1);

    if (ok)
        cout << "NO CYCLE";
    else
        cout << "CYCLE";
}
