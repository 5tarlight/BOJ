#include <iostream>
#include <algorithm>

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
    sort(a, a + n);
    int m;
    cin >> m;

    int start = 0;
    int end = a[n - 1];
    int ans;

    while (start <= end) {
        int sum = 0;
        int mid = (start + end) / 2;
        for (int i = 0; i < n; i++)
            sum += min(a[i], mid);

        if (m >= sum) {
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    cout << ans;
}
