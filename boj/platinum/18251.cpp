#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

typedef long long ll;

pair<ll, ll> arr[262144];
ll s[262144];
ll n, cnt, d;

void dfs(ll x, ll dd) {
    if (x * 2 <= n)
        dfs(x * 2, dd + 1);

    cnt++;
    arr[cnt] = { dd, s[x] };
    d = max(d, dd);

    if (x * 2 + 1 <= n)
        dfs(x * 2 + 1, dd + 1);
}

int main() {
    fio();

    cin >> n;
    queue<pair<ll, ll>> q;

    for (int i = 0; i < n; i++)
        cin >> s[i + 1];

    dfs(1, 1);

    ll ans = -1e18;
    for (int i = 1; i <= d; i++) {
        for (int j = i; j <= d; j++) {
            ll tmp = 0;
            for (int k = 1; k <= n; k++) {
                if (arr[k].first < i || arr[k].first > j)
                    continue;

                tmp += arr[k].second;
                ans = max(ans, tmp);
                if (tmp < 0)
                    tmp = 0;
            }
        }
    }

    cout << ans;
}
