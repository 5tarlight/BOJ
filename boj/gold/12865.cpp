#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    int w[n];
    int v[n];
    for (int i = 0; i < n; i++)
        cin >> w[i] >> v[i];

    int bag[n + 1][k + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (i == 0 || j == 0)
                bag[i][j] = 0;
            else if (w[i - 1] <= j)
                bag[i][j] = max(v[i - 1] + bag[i - 1][j - w[i - 1]], bag[i - 1][j]);
            else
                bag[i][j] = bag[i - 1][j];
        }
    }

    cout << bag[n][k];
}
