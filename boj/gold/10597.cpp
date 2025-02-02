#include "bits/stdc++.h"

using namespace std;

string s;
int ans[50];
bool used[51];
int n;
bool found;

void find(int idx, int cnt = 0) {
    if (found) return;
    if (cnt == n) {
        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
        found = true;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (used[i]) continue;

        if (i < 10) {
            if (s[idx] == i + '0') {
                used[i] = true;
                ans[cnt] = i;
                find(idx + 1, cnt + 1);
                used[i] = false;
            }
        } else {
            if (s[idx] == i / 10 + '0' && idx + 1 < s.size() && s[idx + 1] == i % 10 + '0') {
                used[i] = true;
                ans[cnt] = i;
                find(idx + 2, cnt + 1);
                used[i] = false;
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> s;
    int l = s.size();
    if (l < 10) // 1~9
        n = l;
    else
        n = 9 + (l - 9) / 2;

    find(0);
}
