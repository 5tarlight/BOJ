#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int a[4];
        cin >> a[0] >> a[1] >> a[2] >> a[3];
        sort(a, a + 4);

        if (
            (a[0] == 0 && a[1] == 1 && a[2] == 2 && a[3] == 3) ||
            (a[0] == 0 && a[1] == 2 && a[2] == 4 && a[3] == 6) ||
            (a[0] == 0 && a[1] == 1 && a[2] == 4 && a[3] == 5) ||
            (a[0] == 0 && a[1] == 1 && a[2] == 2 && a[3] == 3) ||
            (a[0] == 2 && a[1] == 3 && a[2] == 6 && a[3] == 7) ||
            (a[0] == 1 && a[1] == 3 && a[2] == 5 && a[3] == 7) ||
            (a[0] == 4 && a[1] == 5 && a[2] == 6 && a[3] == 7)
        )
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
