#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int x[n];
    int y[n];
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    int q;
    cin >> q;
    while (q--) {
        double a;
        cin >> a;
        int idx = lower_bound(x, x + n, a) - x;
        idx--;
        int dy = y[idx + 1] - y[idx];

        if (dy == 0)
            cout << "0\n";
        else if (dy > 0)
            cout << "1\n";
        else
            cout << "-1\n";
    }
}
