#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int v, e;
vector<vector<int>> graph;
stack<int> s;
vector<int> visited;
vector<bool> scc;
vector<vector<int>> group;
int order = 0;

int findScc(int idx) {
    int ans = visited[idx] = ++order;
    s.push(idx);

    for (int i = 0; i < graph[idx].size(); i++) {
        int next = graph[idx][i];

        if (visited[next] == 0)
            ans = min(ans, findScc(next));
        else if (!scc[next])
            ans = min(ans, visited[next]);
    }

    if (ans == visited[idx]) {
        vector<int> temp;
        while (true) {
            int top = s.top();
            s.pop();
            temp.push_back(top);
            scc[top] = true;

            if (top == idx)
                break;
        }

        group.push_back(temp);
    }

    return ans;
}

bool cmp(vector<int> &a, vector<int> &b) {
    return a[0] < b[0];
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> v >> e;
    graph.resize(v + 1);
    visited.resize(v + 1);
    scc.resize(v + 1);

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    for (int i = 1; i <= v; i++)
        if (visited[i] == 0)
            findScc(i);

    for (int i = 0; i < group.size(); i++)
        sort(group[i].begin(), group[i].end());
    sort(group.begin(), group.end(), cmp);

    cout << group.size() << '\n';
    for (int i = 0; i < group.size(); i++) {
        for (int j = 0; j < group[i].size(); j++)
            cout << group[i][j] << ' ';
        cout << "-1\n";
    }
}
