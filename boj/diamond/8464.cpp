#include "bits/stdc++.h"

using namespace std;

#define MAX 1340000
using ll = long long;

ll arr[MAX];

ll mertens(ll k) {
    ll cnt = 0;
    for (ll i = 1; i * i <= k; i++) {
        cnt += arr[i] * k / (i * i);
    }
    return cnt;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll k;
    cin >> k;

    arr[1] = 1;
    for (ll i = 1; i <= MAX; i++) {
        for (int j = 2 * i; j <= MAX; j += i) {
            arr[j] -= arr[i];
        }
    }

    ll first = 0, last = 1e11;
    while (first < last - 1) {
        ll mid = (first + last) / 2;
        if (mid - mertens(mid) < k) first = mid;
        else last = mid;
    }

    cout << last;
}
