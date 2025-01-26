#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;
    int cnt[n + 1];
    fill(cnt, cnt + n + 1, 0);
    vector<int> req[n + 1];

    while (m--) {
        int x, y;
        cin >> x >> y;
        req[y].push_back(x);
    }

    bool good = true;

    while (k--) {
        int x, y;
        cin >> x >> y;

        if (x == 2) {
            if (cnt[y] == 0) {
                good = false;
                break;
            } else {
                cnt[y]--;
            }
        } else {
            bool found = false;
            for (auto v : req[y]) {
                if (cnt[v] == 0) {
                    found = true;
                    break;
                }
            }

            if (found) {
                good = false;
                break;
            } else
                cnt[y]++;
        }
    }

    if (good) cout << "King-God-Emperor";
    else cout << "Lier!";
}
