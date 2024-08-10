#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, c;
    cin >> n >> c;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);

    int left = 1;
    int right = a[n - 1] - a[0];

    int ans = -1;
    while (left <= right ) {
        int cnt = 1;
        int mid = (left + right) / 2;
        int prev = a[0];

        for (int i = 1; i < n; i++) {
            if (a[i] - prev >= mid) {
                cnt++;
                prev = a[i];
            }
        }

        if (cnt >= c) {
            ans = max(ans, mid);
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << ans;
}
