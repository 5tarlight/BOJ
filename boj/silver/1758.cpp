#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n, greater<>());

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += max(0, a[i] - i);
    }

    cout << ans;
}
