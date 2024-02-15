#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int a[7];
int ans[7];

void backtrack(int d) {
    if (d == m) {
        for (int i = 0; i < m; i++)
            cout << ans[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++) {
        ans[d] = a[i];
        backtrack(d + 1);
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);

    backtrack(0);
}
