#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (a < b)
        swap(a, b);

    return b ? gcd(b, a % b) : a;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, s;
    cin >> n >> s;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= s;
        if (a[i] < 0)
            a[i] = -a[i];
    }

    int ans = a[0];
    for (int i = 1; i < n; i++)
        ans = gcd(ans, a[i]);

    cout << ans;
}
