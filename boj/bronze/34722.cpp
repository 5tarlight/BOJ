#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    int n; cin >> n;
    int ans = 0;

    while (n--) {
        int s, c, a, r;
        cin >> s >> c >> a >> r;
        if (s >= 1000 || c >= 1600 || a >= 1500 || r != -1 && r <= 30) ans++;
    }

    cout << ans;
}
