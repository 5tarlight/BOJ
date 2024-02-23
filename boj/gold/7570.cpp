#include <iostream>
#include <algorithm>

using namespace std;

int dp[1000001];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int lis = 0;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        lis = max(lis, dp[num] = dp[num - 1] + 1);
    }

    cout << n - lis;
}
