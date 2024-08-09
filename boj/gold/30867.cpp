#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int l, n;
    cin >> l >> n;
    string s;
    cin >> s;

    int cnt = 0;
    for (int i = 0; i < l; i++) {
        if (s[i] == 'w') cnt++;
        else if (s[i] == 'h') {
            cnt = min(cnt, n);
            s[i] = 'w';
            s[i - cnt] = 'h';
        } else cnt = 0;
    }

    cout << s;
}
