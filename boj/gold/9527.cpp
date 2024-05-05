#include <iostream>
#include <vector>

using namespace std;

long long dp[56];

long long cnt(long long n) {
    vector<int> v;
    long long temp = n;
    while (temp) {
        v.push_back(temp % 2);
        temp /= 2;
    }

    long long ans = 0;
    for (int i = v.size() - 1; i >= 0; i--) {
        if (v[i] == 1) {
            ans += dp[i - 1] + n - (1LL << i) + 1;
            n -= 1L << i;
        }
    }

    return ans;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    long long a, b;
    cin >> a >> b;

    dp[0] = 1;
    for (int i = 1; i <= 55; i++)
        dp[i] = dp[i - 1] * 2 + (1LL << i);

    cout << cnt(b) - cnt(a - 1);
}
