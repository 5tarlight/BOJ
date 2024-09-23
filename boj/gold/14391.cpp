#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int graph[n][m];

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
            graph[i][j] = s[j] - '0';
    }

    int ans = 0;
    for (int bit = 0; bit < (1 << (n * m)); bit++) {
        int temp = 0;

        // Check row
        int prev = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (bit & (1 << (i * m + j))) {
                    temp += prev;
                    prev = 0;
                } else {
                    prev = 10 * prev + graph[i][j];
                }
            }

            temp += prev;
            prev = 0;
        }

        // Check col
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (bit & (1 << (i + j * m))) {
                    prev = 10 * prev + graph[j][i];
                } else {
                    temp += prev;
                    prev = 0;
                }
            }

            temp += prev;
            prev = 0;
        }

        ans = max(ans, temp);
    }

    cout << ans;
}
