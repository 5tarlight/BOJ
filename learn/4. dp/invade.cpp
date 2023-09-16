#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    int arr[n], dp[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);

    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i - 2] + arr[i], dp[i - 1]);
    }

    cout << dp[n - 1];
}
