#include <bits/stdc++.h>

using namespace std;

int main() {
    int cur = 0;
    string s;
    cin >> s;
    int ans = 0;

    char prev = ' ';
    for (char c : s) {
        if (c == '(') {
            prev = c;
            cur++;
        } else {
            cur--;
            if (prev == '(')
                ans += cur;
            else
                ans++;
            prev = c;
        }
    }

    cout << ans;
}
