#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = 0;
    for (int l = 0; l < s.size(); l++) {
        for (int e = l + 3; e <= s.size(); e++) {
            if (s[l] != 'A' || s[e - 1] != 'A') continue;

            int cnt = 0;
            bool good = true;
            for (int i = l + 1; i < e - 1; i++) {
                if (s[i] == 'A') {
                    good = false;
                    break;
                } else if (s[i] == 'N') {
                    cnt++;
                }
            }

            if (cnt != 1)
                good = false;

            if (good)
                ans++;
        }
    }

    cout << ans;
}
