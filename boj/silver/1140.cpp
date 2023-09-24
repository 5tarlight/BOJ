#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> graph[100];
int visited[100];

void dfs(int x) {
    for (int y : graph[x]) {
        if (visited[y] == 0) {
            visited[y] = 1;
            dfs(y);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int v;
            cin >> v;

            if (v == 1)
                graph[i].push_back(j);
        }
    }

    for (int i = 0; i < n; i++) {
        memset(visited, 0, sizeof(visited));
        dfs(i);

        for (int j = 0; j < n; j++)
            cout << visited[j] << ' ';
        cout << '\n';
    }
}
