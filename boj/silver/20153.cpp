#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int a[n];
    int target = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        target ^= a[i];
    }

    int ans = target;

    for (int i = 0; i < n; i++) {
        int temp = target ^ a[i];
        if (temp > ans) {
            ans = temp;
        }
    }

     cout << ans << ans;
}
