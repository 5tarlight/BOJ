#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll ans;
ll n, k;

void solve(ll l, ll r) {
    ll mid = (l + r) / 2;
    ll cnt = 0;

    if (l <= r) {
        for (ll base = 1; base <= n; base++)
            cnt += min(n, mid / base);

        if (l == r) {
            ans = l;
            return;
        }

        if (cnt < k)
            solve(mid + 1, r);
        else
            solve(l, mid);
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    solve(1, n * n);
    cout << ans;
}
