#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++) {
        int s = 0;
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            s += a[i][j];
            a[i][j] = s;
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--; x2--; y2--;
        int s = 0;
        for (int i = x1; i <= x2; i++) {
            s += a[i][y2] - (y1 > 0 ? a[i][y1 - 1] : 0);
        }
        cout << s << '\n';
    }
}
