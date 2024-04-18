#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int p[m];
    for (int i = 0; i < m; i++) {
        cin >> p[i];
    }
    sort(p, p + m, greater<>());

    int prize;
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int amount = min((i + 1), n);
        if (p[i] * amount >= ans) {
            prize = p[i];
            ans = p[i] * amount;
        }
    }

    cout << prize << ' ' << ans;
}
