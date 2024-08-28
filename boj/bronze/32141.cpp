#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, h;
    cin >> n >> h;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        h -= a[i];
        cnt++;
        if (h <= 0) break;
    }

    if (h > 0)
        cout << -1;
    else
        cout << cnt;
}
