#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 1'000'000'000

int v, e;
int graph[401][401];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> v >> e;
    for (int i = 1; i <= v; i++)
        fill(graph[i], graph[i] + v + 1, INF);
    for (int i = 1; i <= v; i++)
        graph[i][i] = 0;

    while (e--) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
    }

    for (int k = 1; k <= v; k++)
        for (int i = 1; i <= v; i++)
            for (int j = 1; j <= v; j++)
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

    int dist = INF;
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            if (i == j)
                continue;

            int d = graph[i][j] + graph[j][i];
            if (d < dist)
                dist = d;
        }
    }

    if (dist == INF)
        cout << -1;
    else
        cout << dist;
}
