#include <iostream>
#include <algorithm>

#define INF 1e9

using namespace std;

int n, m, r;
int arr[100];
int graph[100][100];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> r;

    for (int i = 0; i < n; i++) {
        fill(graph[i], graph[i] + n, INF);
    }

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    while (r--) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a - 1][b - 1] = c;
        graph[b - 1][a - 1] = c;
    }

    for (int i = 0; i < n; i++) {
        graph[i][i] = 0;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (graph[i][j] <= m) {
                sum += arr[j];
            }
        }
        ans = max(ans, sum);
    }

    cout << ans;
}
