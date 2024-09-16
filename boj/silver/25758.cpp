#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    unordered_map<string, int> cnt;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        cnt[s]++;
    }

    set<char> ans;

    for (auto [s1, c1] : cnt) {
        for (auto [s2, c2] : cnt) {
            if (s1 == s2 && c1 == 1) continue;

            ans.insert(max(s1[0], s2[1]));
        }
    }

    cout << ans.size() << '\n';
    for (char c : ans)
        cout << c << ' ';
}
