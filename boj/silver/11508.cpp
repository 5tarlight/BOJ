#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n, greater<>());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i + 2 < n) {
            ans += arr[i] + arr[i + 1];
            i += 2;
        } else {
            ans += arr[i];
        }
    }

    cout << ans;
}
