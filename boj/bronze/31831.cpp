#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int cur = 0;

    int cnt = 0;
    while (n--) {
        int x;
        cin >> x;
        cur = max(0, cur + x);

        if (cur >= m) cnt++;
    }

    cout << cnt;
}
