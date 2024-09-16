#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    long long a, b;
    cin >> a >> b;

    vector<long long> cnt;
    for (long long i = 0; (1LL << i) <= b; i++) {
        long long n = 1LL << i;
        long long c = b / n - a / n;
        if (a % n == 0) c++;
        cnt.push_back(c);
    }

    long long prev = 0;
    long long ans = 0;
    for (int i = cnt.size() - 1; i >= 0; i--) {
        ans += (1LL << i) * (cnt[i] - prev);
        prev = cnt[i];
    }

    cout << ans;
}
