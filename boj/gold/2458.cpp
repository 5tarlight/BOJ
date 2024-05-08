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
    for (int i = 1; i <= n; i++) {
        fill(graph[i], graph[i] + n + 1, 1e9);
        graph[i][i] = 0;
    }
    while (m--) {
        int a, b;
        cin >> a >> b;
        graph[b][a] = 1;
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (graph[i][j] > graph[i][k] + graph[k][j])
                    graph[i][j] = graph[i][k] + graph[k][j];

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++)
            if (graph[i][j] != 1e9 || graph[j][i] != 1e9)
                cnt++;
        if (cnt == n)
            ans++;
    }

    cout << ans;
}
