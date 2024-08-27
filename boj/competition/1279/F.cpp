#include <iostream>

using namespace std;

long long ans = 0;
int n, m;

void solve(int x, int d) {
    if (d == m + 1)
        return;
    ans += x;

    if (x & 1) {
        solve(x / 2, d + 1);
        solve(x / 2 + 1, d + 1);
    } else {
        solve(x / 2, d + 1);
        solve(x / 2, d + 1);
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    solve(n, 0);

    cout << ans;
}
