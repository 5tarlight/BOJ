#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> lgcd(n), rgcd(n);
    lgcd[0] = a[0];
    for (int i = 1; i < n; i++) {
        lgcd[i] = gcd(lgcd[i - 1], a[i]);
    }

    rgcd[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        rgcd[i] = gcd(rgcd[i + 1], a[i]);
    }

    int ans = -1;
    int maxGcd = -1;

    if (a[n - 1] % lgcd[n - 2] != 0) {
        ans = a[n - 1];
        maxGcd = lgcd[n - 2];
    }

    if (a[0] % rgcd[1] != 0 && maxGcd < rgcd[1]) {
        ans = a[0];
        maxGcd = rgcd[1];
    }

    for (int i = 1; i < n - 1; i++) {
        int nxt = gcd(lgcd[i - 1], rgcd[i + 1]);
        if (a[i] % nxt != 0 && nxt > maxGcd) {
            maxGcd = nxt;
            ans = a[i];
        }
    }

    if (ans == -1) {
        cout << -1 << endl;
    } else {
        cout << maxGcd << " " << ans << endl;
    }

    return 0;
}
