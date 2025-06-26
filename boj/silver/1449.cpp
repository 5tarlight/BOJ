#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    int ans = 0;
    int prev = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] - prev >= k) {
            ans++;
            prev = a[i];
        }
    }

    cout << ans + 1;
}
