#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;
        cout << gcd(a, b) << '\n';
    }
}
