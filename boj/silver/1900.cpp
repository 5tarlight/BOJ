#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    int n; cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];

    int win[n];
    memset(win, 0, sizeof(win));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int ta = a[i] + b[i] * a[j];
            int tb = a[j] + b[j] * a[i];
            if (ta > tb) win[i]++;
            else if (ta < tb) win[j]++;
        }
    }

    pair<int, int> ans[n];
    for (int i = 0; i < n; i++)
        ans[i] = { win[i], i + 1 };
    sort(ans, ans + n, greater<>());

    for (int i = 0; i < n; i++)
        cout << ans[i].second << '\n';
}
