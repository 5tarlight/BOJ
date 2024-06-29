#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int a[n + 1];
    int ans[n + 1];

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int idx = -1;
    for (int i = n; i >= 2; i--) {
        ans[i] = idx;
        if (a[i - 1] != a[i])
            idx = i;
    }

    ans[1] = idx;

    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
}
