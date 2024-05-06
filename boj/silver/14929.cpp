#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int a[n + 1];
    a[0] = 1;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int sum[n + 1];
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[i];

    long long ans = 0;
    for (int i = 1; i < n; i++)
        ans += a[i] * (sum[n] - sum[i]);

    cout << ans;
}
