#include <iostream>

using namespace std;

int f[200001][20];
int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int m;
    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> f[i][0];

    for (int j = 1; j < 20; j++)
        for (int i = 1; i <= m; i++)
            f[i][j] = f[f[i][j - 1]][j - 1];

    int q;
    cin >> q;
    while (q--) {
        int n, x;
        cin >> n >> x;

        for (int i = 0; n > 0; i++) {
            if (n & 1)
                x = f[x][i];
            n >>= 1;
        }

        cout << x << '\n';
    }
}
