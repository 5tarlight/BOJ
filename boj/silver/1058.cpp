#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    int n;
    cin >> n;
    char graph[n][n + 1];
    for (int i = 0; i < n; i++)
        cin >> graph[i];

    int dist[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = (graph[i][j] == 'Y') ? 1 : 1e9;

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++)
            if (dist[i][j] <= 2 && i != j)
                cnt++;

        ans = max(ans, cnt);
    }

    cout << ans;
}
