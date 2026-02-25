#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

     int n, m, r; cin >> n >> m >> r;
    int a[n], b[m];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    vector<int> dist;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            dist.push_back(abs(a[i] - a[j]));

    sort(dist.begin(), dist.end());

    double ans = 0;
    cout << fixed << setprecision(1);
    for (int i = 0; i < m; i++) {
        long long x = (2LL * r) / b[i];
        int idx = upper_bound(dist.begin(), dist.end(), x) - dist.begin() - 1;
        if (idx < 0) continue;
        double area = (double)dist[idx] * b[i] / 2;
        ans = max(ans, area);
    }

    if (ans == 0)
        cout << -1;
    else
        cout << ans;
}
