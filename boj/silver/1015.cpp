#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end());
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
        ans[a[i].second] = i;

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
}
