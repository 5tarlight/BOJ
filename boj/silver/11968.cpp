#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int a[n], b[n];
    bool used[2 * n + 1];
    fill(used, used + 2 * n + 1, false);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        used[b[i]] = true;
    }
    sort(b, b + n);
    int idx = 0;
    for (int i = 1; i <= 2 * n; i++)
        if (!used[i])
            a[idx++] = i;

    int ans = 0;
    idx = 0;
    for (int i = 0; i < n; i++) {
        while (idx < n && a[idx] < b[i])
            idx++;

        if (idx >= n) break;

        ans++;
        idx++;
    }

    cout << ans;
}
