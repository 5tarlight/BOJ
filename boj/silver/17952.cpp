#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    stack<pair<int, int>> s;
    int n; cin >> n;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int op; cin >> op;
        if (op == 1) {
            int a, t; cin >> a >> t;
            if (t == 1)
                ans += a;
            else
                s.push({a, t - 1});
        } else if (!s.empty()) {
            auto [a, t] = s.top();
            s.pop();
            t--;

            if (t == 0) {
                ans += a;
            } else {
                s.push({a, t});
            }
        }
    }

    cout << ans;
}
