#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }

    return a;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    int dp[1001];
    dp[0] = 0;
    dp[1] = 3;

    for (int i = 2; i <= 1000; i++) {
        int cnt = 0;
        for (int j = 1; j <= i; j++) {
            if (gcd(i, j) == 1) {
                cnt += 2;
            }
        }
        dp[i] = dp[i - 1] + cnt;
    }

    while (t--) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
}
