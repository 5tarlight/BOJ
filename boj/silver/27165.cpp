#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int a[n + 1];
    int from = -1;
    int to = -1;
    bool exceeded = false;
    for (int i = 0; i <= n; i++) {
        cin >> a[i];

        if (a[i] == 1) {
            if (from == -1) {
                from = i;
            } else if (to == -1) {
                to = i;
            } else {
                exceeded = true;
            }
        }
    }
    int x;
    cin >> x;

    if (exceeded) {
        cout << "NO";
        return 0;
    }

    if (from != -1 && to != -1)  {
        if (from + x == to) {
            cout << "YES\n";
            cout << from << ' ' << to;
        } else {
            cout << "NO";
        }
    } else if (from != -1) {
        if (from + x <= n && a[from + x] > 0) {
            cout << "YES\n";
            cout << from << ' ' << from + x;
        } else {
            if (from - x >= 0 && (a[from - x] > 2 || a[from - x] == 1)) {
                cout << "YES\n";
                cout << from - x << ' ' << from;
            } else
                cout << "NO";
        }
    } else {
        bool ok = false;

        for (int i = 0; i + x <= n; i++) {
            if (a[i] > 2 && a[i + x] > 1) {
                ok = true;
                cout << "YES\n";
                cout << i << ' ' << i + x;
                break;
            }
        }

        if (!ok)
            cout << "NO";
    }
}
