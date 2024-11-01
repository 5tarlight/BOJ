#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    unordered_map<string, int> cnt;
    int n;
    cin >> n;

    while (n--) {
        int a, b;
        cin >> a >> b;
        while (b--) {
            string s;
            cin >> s;
            cnt[s]++;
        }
    }

    string ans;
    int max = -1;
    bool ok = true;
    for (const auto& [s, c] : cnt) {
        if (max < c) {
            max = c;
            ans = s;
            ok = true;
        } else if (max == c) {
            ok = false;
        }
    }

    if (ok)
        cout << ans;
    else
        cout << -1;
}
