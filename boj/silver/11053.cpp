#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    int nums[n + 1];
    int dp[n + 1];

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int temp = 1;
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j])
                temp = max(temp, dp[j] + 1);
        }
        dp[i] = temp;
        ans = max(temp, ans);
    }

    cout << ans;
}
