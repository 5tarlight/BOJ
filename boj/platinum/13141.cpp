#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int graph[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
        fill(graph[i], graph[i] + n + 1, 1e9);
    pair<pair<int, int>, int> e[m];
    for (int i = 0; i <= n; i++)
        graph[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        e[i] = {{ a, b }, c };
        graph[a][b] = min(graph[a][b], c);
        graph[b][a] = min(graph[b][a], c);
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (graph[i][k] + graph[k][j] < graph[i][j])
                    graph[i][j] = graph[i][k] + graph[k][j];

    int ans = 1e9;
    for (int i = 1; i <= n; i++) {
        int tmp = 0;
        for (auto [p, cost] : e)
            tmp = max(tmp, graph[i][p.first] + graph[i][p.second] + cost);
        ans = min(ans, tmp);
    }

    cout << ans / 2 << '.' << (ans & 1) * 5;
}
