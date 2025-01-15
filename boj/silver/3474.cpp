#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long ans = 0;
        while (n) {
            ans += n / 5;
            n /= 5;
        }
        cout << ans << '\n';
    }
}
