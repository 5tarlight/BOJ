#include <iostream>
#include <vector>
#include <cstring> // memset
#include <algorithm>

using namespace std;

int N, M, R;
int cnt = 1;

void dfs(vector<int> *graph, bool *visited, int start, int *sec) {
    visited[start - 1] = true;
    sec[start - 1] = cnt;
    cnt++;

    for (int j : graph[start - 1]) {
        if (!visited[j - 1])
            dfs(graph, visited, j,  sec);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> R;

    vector<int> graph[M];
    int sec[N];
    bool visited[N];
    memset(visited, false, sizeof(visited));
    memset(sec, 0, sizeof(sec));

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b);
        graph[b - 1].push_back(a);
    }

    for (int i = 0; i < M; i++) {
        if (!graph[i].empty())
            sort(graph[i].begin(), graph[i].end());
    }

    dfs(graph, visited, R, sec);

    for (int s : sec)
        cout << s << "\n";
}
