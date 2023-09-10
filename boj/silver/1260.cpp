#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, V;
vector<int> graph[1001];
bool dfsVisit[1001];
vector<int> dfsTrail;
bool bfsVisit[1001];
vector<int> bfsTrail;

void dfs(int x) {
    dfsVisit[x] = true;
    dfsTrail.push_back(x);

    for (int y : graph[x]) {
        if (!dfsVisit[y])
            dfs(y);
    }
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    bfsVisit[start] = true;

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        bfsVisit[x] = true;
        bfsTrail.push_back(x);

        for (int y : graph[x])
            if (!bfsVisit[y]) {
                q.push(y);
                bfsVisit[y] = true;
            }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> V;

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for (auto& i : graph) {
        if (!i.empty())
            sort(i.begin(), i.end());
    }

    dfs(V);
    bfs(V);

    for (int e : dfsTrail) {
        cout << e << ' ';
    }
    cout << "\n";
    for (int e : bfsTrail) {
        cout << e << ' ';
    }
}
