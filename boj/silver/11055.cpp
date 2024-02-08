#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int a[n];
    int dp[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[i] = a[i];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                if (dp[i] < dp[j] + a[i]) {
                    dp[i] = dp[j] + a[i];
                }
            }
        }
    }

    int max = 0;
    for (int i = 0; i < n; i++)
        if (max < dp[i])
            max = dp[i];

    cout << max;
}
