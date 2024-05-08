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

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        for (int j = i + 1; j < n; j++) {
            ans = max(ans, a[j] - a[i]);
        }
    }

    cout << ans;
}
