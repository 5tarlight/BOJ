#include "bits/stdc++.h"

using namespace std;

int main() {
    int n, k, a, b;
    cin >> n >> k >> a >> b;

    int ans1 = a * (n - 1);
    int ans2 = b * (k + n - 2);
    cout << ans2 << ' ' << ans1;
}
