#include <iostream>

using namespace std;

bool notPair[201][201];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        notPair[a][b] = notPair[b][a] = true;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (notPair[i][j])
                continue;

            for (int k = j + 1; k <= n; k++) {
                if (notPair[i][k] || notPair[j][k])
                    continue;
                ans++;
            }
        }
    }

    cout << ans;
}
