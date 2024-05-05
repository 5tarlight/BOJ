#include <iostream>
#include <vector>

using namespace std;

int ver, edge;
vector<vector<int>> graph;
vector<int> visited;
vector<bool> isCut;
int order = 0;
int ans = 0;

int cntCut(int idx, bool isRoot) {
    visited[idx] = ++order;
    int ret = visited[idx];
    int child = 0;

    for (int i = 0; i < graph[idx].size(); i++) {
        int next = graph[idx][i];
        if (visited[next] == -1) {
            child++;
            int low = cntCut(next, false);

            if (!isRoot && low >= visited[idx] && !isCut[idx]) {
                isCut[idx] = true;
                ans++;
            }

            ret = min(ret, low);
        } else {
            ret = min(ret, visited[next]);
        }
    }

    if (isRoot) {
        isCut[idx] = (child >= 2);

        if (isCut[idx])
            ans++;
    }

    return ret;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> ver >> edge;
    graph.resize(ver + 1);
    visited.resize(ver + 1, -1);
    isCut.resize(ver + 1, false);

    for (int i = 0; i < edge; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= ver; i++)
        if (visited[i] == -1)
            cntCut(i, true);

    cout << ans << '\n';

    for (int i = 1; i <= ver; i++)
        if (isCut[i])
            cout << i << ' ';
}
