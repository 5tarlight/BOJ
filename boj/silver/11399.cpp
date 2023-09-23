#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> times;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        times.push_back(t);
    }

    sort(times.begin(), times.end());

    int sum = times[0];
    int dp[n];
    dp[0] = times[0];

    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1] + times[i];
        sum += dp[i];
    }

    cout << sum;
}
