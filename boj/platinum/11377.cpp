#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

constexpr int MAX = 1010;

vector<int> adj[MAX];
int match[MAX];
bool visited[MAX];

bool dfs(int u) {
    for (auto v : adj[u]) {
        if (visited[v]) continue;
        visited[v] = true;

        if (!match[v] || dfs(match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
    fio();

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        int c;
        cin >> c;
        while (c--) {
            int job;
            cin >> job;
            adj[i].push_back(job);
        }
    }

    int matchCnt = 0;

    for (int i = 1; i <= n; i++) {
        fill(visited, visited + MAX, false);
        if (dfs(i)) matchCnt++;
    }

    for (int i = 1; i <= n && k > 0; i++) {
        fill(visited, visited + MAX, false);
        if (dfs(i)) {
            matchCnt++;
            k--;
        }
    }

    cout << matchCnt;
}