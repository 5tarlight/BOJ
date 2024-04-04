#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    int n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            cin >> a[i];
            continue;
        }
        int num;
        cin >> num;
        a[i] = a[i - 1] + num;
    }

    int m;
    cin >> m;
    ll b[m];
    for (int i = 0; i < m; i++) {
        if (i == 0) {
            cin >> b[i];
            continue;
        }
        int num;
        cin >> num;
        b[i] = b[i - 1] + num;
    }

    vector<ll> a_sum;
    vector<ll> b_sum;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            a_sum.push_back(a[j] - (i == 0 ? 0 : a[i - 1]));
        }
    }
    sort(a_sum.begin(), a_sum.end());

    for (int i = 0; i < m; i++) {
        for (int j = i; j < m; j++) {
            b_sum.push_back(b[j] - (i == 0 ? 0 : b[i - 1]));
        }
    }
    sort(b_sum.begin(), b_sum.end());

    ll ans = 0;
    for (long long i : a_sum) {
        ll target = t - i;
        auto range = equal_range(b_sum.begin(), b_sum.end(), target);
        ans += range.second - range.first;
    }

    cout << ans;
}
