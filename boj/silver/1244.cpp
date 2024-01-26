#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int t;
    cin >> t;

    while (t--) {
        int s, p;
        cin >> s >> p;

        if (s == 1) {
            for (int i = p - 1; i < n; i += p) {
                a[i] = a[i] == 1 ? 0 : 1;
            }
        } else {
            int d = 1;
            a[p - 1] = a[p - 1] == 1 ? 0 : 1;
            while (p - d - 1 >= 0 && p + d - 1 < n && a[p + d - 1] == a[p - d - 1]) {
                a[p - d - 1] = a[p - d - 1] == 0 ? 1 : 0;
                a[p + d - 1] = a[p + d - 1] == 0 ? 1 : 0;
                d++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (i != 0 && i % 20 == 0)
            cout << '\n';
        cout << a[i] << ' ';
    }
}
