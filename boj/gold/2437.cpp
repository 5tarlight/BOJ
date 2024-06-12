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
    sort(a, a + n);

    int ans = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] > ans)
            break;
        ans += a[i];
    }

    cout << ans;
}
