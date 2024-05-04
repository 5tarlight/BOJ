#include <iostream>

using namespace std;

int cnt[1001];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, p;
    cin >> n >> p;
    cnt[n] = 1;

    int ans;
    int m = n;
    while (true) {
        int prev = m;
        m = (m * n) % p;

        if (cnt[m] == 0)
            cnt[m] = cnt[prev] + 1;
        else {
            ans = cnt[prev] - cnt[m] + 1;
            break;
        }
    }

    cout << ans;
}
