#include <iostream>
#include <cmath>

using namespace std;

void solve(int f, int t, int k) {
    if (k == 1) {
        cout << f << ' ' << t << '\n';
        return;
    }

    int other = 6 - f - t;
    solve(f, other, k - 1);
    solve(f, t, 1);
    solve(other, t, k - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int k;
    cin >> k;
    int n = (int)pow(2, k) - 1;

    cout << n << '\n';
    solve(1, 3, k);
}
