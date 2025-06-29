#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    int n; cin >> n;
    unordered_set<int> s;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        s.insert(a);
    }
    int x; cin >> x;

    int ans = 0;
    for (int i = 1; i <= x; i++) {
        for (int j = x; j <= 1000; j++) {
            if (i >= j) continue;

            bool good = true;
            for (int k = i; k <= j; k++) {
                if (s.count(k)) {
                    good = false;
                    break;
                }
            }

            if (good) {
                ans++;
            }
        }
    }

    cout << ans;
}
