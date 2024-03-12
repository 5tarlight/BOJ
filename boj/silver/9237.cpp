#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    long long arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, arr[i] + n - i);
    }

    cout << ans + 1;
}
