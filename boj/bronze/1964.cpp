#include "bits/stdc++.h"

using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 5;
    int gap = 7;

    n--;
    while (n--) {
        ans += gap;
        gap += 3;
        gap %= 45678;
        ans %= 45678;
    }

    cout << ans;
}
