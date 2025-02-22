#include "bits/stdc++.h"

using namespace std;

int main() {
    long long n;
    int  l;
    cin >> n >> l;

    for (int len = l; len <= 100; len++) {
        long double tmp = (2.0 * n / len - len + 1) / 2.0;
        if (tmp < 0) continue;
        if (tmp == (long long)tmp) {
            long long t = (long long)tmp;
            for (int i = 0; i < len; i++)
                cout << t + i << ' ';
            return 0;
        }
    }

    cout << -1;
}