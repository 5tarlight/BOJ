#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int ans = 0;
    int day = 0;

    while (true) {
        bool found = false;

        for (int i = 0; i + k < n; i++) {
            if (a[i] == a[i + k]) continue;

            found = true;
            int diff = a[i + k] - a[i];
            ans += diff;
            a[i + k] -= diff;
            day++;
            sort(a, a + n);
            break;
        }

        if (!found) break;
    }

    cout << ans << ' ' << day;
}
