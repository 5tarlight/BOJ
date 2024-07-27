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
    int l = 0, r = 0;
    int odds = 0;

    while (r < n) {
        if (a[r] & 1)
            odds++;

        while (odds > k) {
            if (a[l] & 1)
                odds--;
            l++;
        }

        ans = max(ans, r - l + 1 - odds);
        r++;
    }

    cout << ans;
    return 0;
}
