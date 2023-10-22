#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int parent[10001];

int find(int x) {
    if (parent[x] == x)
        return x;
    else
        return parent[x] = find(parent[x]);
}

void uni(int x, int y) {
    x = find(x);
    y = find(y);
    parent[y] = x;
}

bool isFamily(int x, int y) {
    return find(x) == find(y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int v, e;
    cin >> v >> e;

    int result = 0;
    vector<tuple<int, int, int>> graph;

    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph.emplace_back(c, a, b);
    }
    sort(graph.begin(), graph.end());

    for (int i = 1; i <= v; i++)
        parent[i] = i;

    for (int i = 0; i < graph.size(); i++) {
        int a, b, c;
        tie(c, a, b) = graph[i];
        if (!isFamily(a, b)) {
            uni(a, b);
            result += c;
        }
    }

    cout << result;
}
