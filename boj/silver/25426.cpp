#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    sort(a, a + n);

    long long ans = 0;
    for (long long i = 1; i <= n; i++)
        ans += i * a[i - 1] + b[i - 1];

    cout << ans;
}
