#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    long long a, b;
    cin >> a >> b;

    long long s = 0;
    long long n = 0;
    while (s < a + b) {
        n++;
        s += n;
    }

    if (s != a + b) {
        cout << -1;
        return 0;
    }

    long long cnt = 0;
    for (long long i = n; i >= 1; i--) {
        if (a >= i) {
            a -= i;
            cnt++;
        }
    }

    if (a != 0) {
        cout << -1;
        return 0;
    }

    cout << cnt;
}
