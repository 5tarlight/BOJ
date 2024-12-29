#include "bits/stdc++.h"

using namespace std;

int toIdx(char c) {
    if (c == 'P') return 0;
    if (c == 'C') return 1;
    if (c == 'V') return 2;
    if (c == 'S') return 3;
    if (c == 'G') return 4;
    if (c == 'F') return 5;
    if (c == 'O') return 6;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    string trash[n];
    for (int i = 0; i < n; i++)
        cin >> trash[i];

    int p[7];
    for (int i = 0; i < 7; i++)
        cin >> p[i];

    long long ans = 0;
    for (string s : trash) {
        char target = s[0];
        for (int i = 1; i < s.size(); i++) {
            if (s[i] != target) {
                target = 'O';
                break;
            }
        }
        ans += min(p[6], p[toIdx(target)]) * s.size();
    }

    cout << ans;
}
