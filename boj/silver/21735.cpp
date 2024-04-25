#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int a[101];
int ans = 0;

void backtrack(int i, int size, int t) {
    if (t == m || i == n + 1) {
        ans = max(ans, size);
        return;
    }

    backtrack(i + 1, size + a[i + 1], t + 1);
    if (i + 2 <= n)
        backtrack(i + 2, size / 2 + a[i + 2], t + 1);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    backtrack(0, 1, 0);

    cout << ans;
}
