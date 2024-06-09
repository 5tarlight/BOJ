#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int dist[n];
    fill(dist, dist + n, -1);
    queue<int> q;
    q.push(0);
    dist[0] = 0;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        int cur = a[v];

        for (int i = 1; i <= cur; i++) {
            if (v + i < n && dist[v + i] == -1) {
                dist[v + i] = dist[v] + 1;
                q.push(v + i);
            }
        }
    }

    cout << dist[n - 1];
}
