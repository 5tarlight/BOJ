#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool visited[100'001];
vector<int> tree[100'001];
vector<int> dist[100'001];
int maxDist = -1;
int maxNode = -1;

void dfs(int start, int d) {
    if (visited[start])
        return;

    if (maxDist < d) {
        maxDist = d;
        maxNode = start;
    }

    visited[start] = true;

    for (int i = 0; i < tree[start].size(); i++) {
        dfs(tree[start][i], d + dist[start][i]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int v;
    cin >> v;

    for (int i = 0; i < v; i++) {
        int c = 0, n = 0, vertex;
        while (true) {
            cin >> n;

            if (n == -1)
                break;
            if (c == 0)
                vertex = n;
            else {
                int d;
                cin >> d;
                tree[vertex].push_back(n);
                dist[vertex].push_back(d);
            }

            c++;
        }
    }

    // 1. 임의의 정점에서 가장 먼 정점 찾기
    // 2. 그 정점과 가장 먼 정점 찾기
    // 3. = 지름
    memset(visited, false, sizeof(visited));
    dfs(1, 0);
    memset(visited, false, sizeof(visited));
    dfs(maxNode, 0);

    cout << maxDist;
}
