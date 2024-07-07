#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[2001];
int n;
bool found;
bool visited[2001];

void dfs(int x, int d) {
    if (d >= 5) {
        found = true;
        return;
    }

    if (found) return;

    for (int i : graph[x]) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(i, d + 1);
            visited[i] = false;
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int m;
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        visited[i] = true;
        dfs(i, 1);
        visited[i] = false;
    }

    cout << (int)found;
}
