#include "bits/stdc++.h"

using namespace std;

int n;
int a[200001];
vector<int> adj[200001];
bool visited[200001];

int dfs(int x, int color) {
    int res = 0;
    if (a[x] != color) {
        res++;
        color = a[x];
    }

    for (int y : adj[x]) {
        if (visited[y]) continue;
        visited[y] = true;
        res += dfs(y, color);
    }

    return res;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    visited[1] = true;
    cout << dfs(1, 0);
}
