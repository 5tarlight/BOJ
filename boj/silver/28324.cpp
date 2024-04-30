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
    for (int i = 0; i < n; i++)
        cin >> a[i];

    long long ans = 0;
    int prev = 0;

    for (int i = n - 1; i >= 0; i--) {
        prev = min(prev + 1, a[i]);
        ans += prev;
    }

    cout << ans;
}
