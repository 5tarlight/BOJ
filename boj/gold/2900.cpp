#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

long long a[1000000];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    map<int, int> cache;
    while (k--) {
        int x;
        cin >> x;
        cache[x]++;
    }

    for (auto [nxt, cnt] : cache) {
        int i = 0;
        while (i < n) {
            a[i] += cnt;
            i += nxt;
        }
    }

    long long sum[n + 1];
    sum[0] = 0;
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[i - 1];

    int m;
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << sum[r + 1] - sum[l] << '\n';
    }
}
